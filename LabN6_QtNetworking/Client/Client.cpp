#include <string>

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QDebug>

#include "Client.h"
#include "Question.h"
#include "mainwindow.h"

using namespace std;

Client::Client(string ip, int port, MainWindow *window, QObject *parent): QObject(parent) {
    this->ip = ip;
    this->port = port;
    this->window = window;
    this->voluntarily = false;

    this->parser = new JSONQuestionParser();
}

Client::~Client() {
    this->closeConnection();
}


bool Client::tryConnect() {
    this->socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    socket->connectToHost(this->ip.c_str(), this->port);

    if (!socket->waitForConnected() || socket->state() != QTcpSocket::ConnectedState) {
        qDebug() << "Error.." << socket->errorString();
        return false;
    } else {
        qDebug() << "Successfully connected";
        return true;
    }
}

void Client::sendAnswer(int answer) {
    this->socket->write(to_string(answer).c_str());
    this->socket->waitForBytesWritten();
}

void Client::closeConnection() {
    this->voluntarily = true;
    this->socket->close();
}

void Client::connected() {

}

void Client::disconnected() {
    if (!this->voluntarily) {
        this->window->makeDisconnect();
    }
}

void Client::readyRead() {
    QString str = socket->readAll();

    QJsonDocument response = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject json = response.object();

    if (json["type"] == "question") {
        Question *question = parser->toQuestion(json);

        window->showQuestion(question);
    } else {
        int score = json["score"].toInt();
        int totalScore = json["totalScore"].toInt();

        window->showUserResult(score, totalScore);
        this->closeConnection();
    }
}
