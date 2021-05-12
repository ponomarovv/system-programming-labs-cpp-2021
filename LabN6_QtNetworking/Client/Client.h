#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

#include <string>

#include "JSONQuestionParser.h"
#include "mainwindow.h"

class MainWindow;

class Client: public QObject {

    Q_OBJECT

    public:
        Client(std::string ip, int port, MainWindow *window, QObject *parent = nullptr);
        ~Client();
        bool tryConnect();
        void sendAnswer(int answer);
        void closeConnection();

    private slots:
        void connected();
        void disconnected();
        void readyRead();

    private:
        std::string ip;
        int port;
        bool voluntarily;
        MainWindow *window;
        JSONQuestionParser *parser;

        QTcpSocket* socket;

};

#endif // CLIENT_H
