#ifndef SERVER_H
#define SERVER_H

#include <string>

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include "Quiz.h"
#include "Question.h"
#include "JSONQuestionParser.h"

class Server: public QObject {
    Q_OBJECT

    public:
        Server(std::string ip, int port, QObject *parent = nullptr);
        bool isListening();

    signals:

    public slots:
        void processConnection();
        void readSocket();
        void disconnected();

    private:
        Quiz *quiz;
        QTcpServer *server;
        JSONQuestionParser *parser;
        bool listening;
        bool socketConnected;

        void sendQuestion(QTcpSocket *socket, Question *question);
        void sendResult(QTcpSocket *socket);
};

#endif // SERVER_H
