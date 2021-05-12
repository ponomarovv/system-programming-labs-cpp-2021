#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>

#include "Server.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void startServer();
        void exit();

    private:
        const std::string LOCAL_IP = "10.0.2.15";
        const int PORT = 4444;

        QPushButton *bStartServer;
        QPushButton *bExit;
        QLabel *lInformation;
        void initWindow();
        Server *server;
};
#endif // MAINWINDOW_H
