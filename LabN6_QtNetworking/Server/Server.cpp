#include <string>
#include <QJsonDocument>
#include <QDebug>

#include "Server.h"
#include "JSONQuestionParser.h"

Server::Server(std::string ip, int port, QObject *parent): QObject(parent) {
    this->listening = false;
    this->socketConnected = false;
    this->server = new QTcpServer(this);
    this->parser = new JSONQuestionParser();

    connect(server, SIGNAL(newConnection()), this, SLOT(processConnection()));

    if (server->listen(QHostAddress(ip.c_str()), port)) {
        this->listening = true;
    }
}

bool Server::isListening() {
    return this->listening;
}

void Server::processConnection() {
    QTcpSocket *socket = server->nextPendingConnection();

    if (this->socketConnected) {
        socket->disconnectFromHost();
        return;
    }

    this->socketConnected = true;

    connect(socket, SIGNAL(readyRead()), this, SLOT(readSocket()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    this->quiz = new Quiz();

    this->sendQuestion(socket, this->quiz->getNextQuestion());
}

void Server::readSocket(){
    QTcpSocket *socket = (QTcpSocket*)sender();

    QByteArray data = socket->readAll();

    if (data.isEmpty()) {
        qDebug() << "Nothing to read";
    } else {
        int answer = data.toInt();
        this->quiz->checkAnswer(answer);

        if (this->quiz->hasNext()) {
            this->sendQuestion(socket, this->quiz->getNextQuestion());
        } else {
            this->sendResult(socket);
        }
    }
}

void Server::sendQuestion(QTcpSocket *socket, Question *question) {
    QJsonObject jsonQuestion = this->parser->toJSON(question);
    jsonQuestion.insert("type", "question");

    QJsonDocument document(jsonQuestion);

    QString value(document.toJson(QJsonDocument::Compact));

    socket->write(value.toStdString().c_str());

    socket->waitForBytesWritten();
}

void Server::sendResult(QTcpSocket *socket) {
    QJsonObject json;
    json.insert("type", "result");
    json.insert("score", this->quiz->getCurrentScore());
    json.insert("totalScore", this->quiz->getTotalScore());

    QJsonDocument document(json);
    QString value(document.toJson(QJsonDocument::Compact));

    socket->write(value.toStdString().c_str());

    socket->waitForBytesWritten();
}

void Server::disconnected() {
    this->socketConnected = false;
}
