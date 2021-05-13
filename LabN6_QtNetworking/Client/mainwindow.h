#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QRadioButton>
#include <QMainWindow>
#include <QPushButton>
#include <QGroupBox>
#include <QLayout>
#include <QWidget>
#include <QLabel>

#include <string>
#include <vector>

#include "Question.h"
#include "Client.h"

class Client;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void showQuestion(Question *question);
        void showUserResult(int score, int totalScore);
        void makeDisconnect();

    private slots:
        void connectToServer();
        void commitUserAnswer();
        void exit();

    private:
//        const std::string LOCAL_HOST_IP = "192.168.0.107"; // this one to use two virtual machines with ubuntu
//        const int PORT = 4444;

        const std::string LOCAL_HOST_IP = "127.0.0.1";
        const int PORT = 4444;

        QLayout *mainLayout;
        QWidget *mainWidget;
        QPushButton *bConnectToServer;
        QPushButton *bCommitAnswer;
        QPushButton *bExit;
        QLabel *questionText;
        QGroupBox *radioGroup;
        std::vector<QRadioButton*> radios;
        Client *client;

        void showMenu();
        void clearAll();
        void clearByLayout(QLayout* layout);
        void addRadios(std::vector<std::string> variants);

};
#endif // MAINWINDOW_H
