#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QApplication>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    this->initWindow();
}

MainWindow::~MainWindow() {}

void MainWindow::initWindow() {
    this->setWindowTitle("QuizServer");

    this->setMinimumSize(100, 50);

    QWidget *mainWidget = new QWidget();
    QLayout *mainLayout = new QVBoxLayout(this);

    lInformation = new QLabel("", this);

    bStartServer = new QPushButton("Start Server", this);
    bExit = new QPushButton("Exit", this);

    connect(bStartServer, SIGNAL(released()), this, SLOT(startServer()));
    connect(bExit, SIGNAL(released()), this, SLOT(exit()));

    mainLayout->addWidget(lInformation);
    mainLayout->addWidget(bStartServer);
    mainLayout->addWidget(bExit);

    mainWidget->setLayout(mainLayout);

    this->setCentralWidget(mainWidget);
}

void MainWindow::startServer() {
    this->server = new Server(LOCAL_IP, PORT);

    if (this->server->isListening()) {
        bStartServer->setEnabled(false);
        lInformation->setText("Server started!");
    } else {
        lInformation->setText("Something went wrong...");
    }
}

void MainWindow::exit() {
    QApplication::exit();
}
