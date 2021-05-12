#include <QDebug>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QRadioButton>
#include <QApplication>

#include <string>
#include <vector>

#include "mainwindow.h"
#include "Client.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    this->setWindowTitle("QuizClient");

    this->setMinimumSize(400, 400);

    this->mainWidget = new QWidget();

    this->setCentralWidget(mainWidget);

    this->showMenu();
}

MainWindow::~MainWindow() {}

void MainWindow::showQuestion(Question *question) {
    this->clearAll();

    mainLayout = new QVBoxLayout();

    this->questionText = new QLabel("");
    this->questionText->setWordWrap(true);
    questionText->setText(QString::fromStdString(question->getText()));

    addRadios(question->getVariants());

    bCommitAnswer = new QPushButton("Commit");
    connect(bCommitAnswer, SIGNAL(released()), this, SLOT(commitUserAnswer()));

    mainLayout->addWidget(questionText);
    mainLayout->addWidget(radioGroup);
    mainLayout->addWidget(bCommitAnswer);

    mainWidget->setLayout(mainLayout);
}

void MainWindow::showMenu() {
    mainLayout = new QVBoxLayout();

    bConnectToServer = new QPushButton("Connect to Quiz Server", this);
    connect(bConnectToServer, SIGNAL(released()), this, SLOT(connectToServer()));

    bExit = new QPushButton("Exit", this);
    connect(bExit, SIGNAL(released()), this, SLOT(exit()));

    mainLayout->addWidget(bConnectToServer);
    mainLayout->addWidget(bExit);

    mainWidget->setLayout(mainLayout);
}

void MainWindow::connectToServer() {
    this->client = new Client(LOCAL_HOST_IP, PORT, this);

    if (!client->tryConnect()) {
        qDebug() << "Something went wrong...";
    }
}

void MainWindow::commitUserAnswer() {
    int selected = -1;
    for (int i = 0; i < (int)radios.size(); i++) {
        if (radios[i]->isChecked()) {
            selected = i;
        }
    }

    if (selected == -1) {
        QMessageBox *box = new QMessageBox();
        string message = "You have to select answer";
        box->setWindowTitle("Error");
        box->setText(message.c_str());
        box->exec();
    } else {
        this->client->sendAnswer(selected);
        this->bCommitAnswer->setDisabled(true);
    }
}

void MainWindow::exit() {
    QApplication::exit();
}

void MainWindow::clearAll() {
    this->clearByLayout(mainLayout);
}

void MainWindow::clearByLayout(QLayout *layout) {
    QLayoutItem *item;
    while ((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearByLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
    delete layout;
}

void MainWindow::showUserResult(int score, int totalScore) {
    QMessageBox *box = new QMessageBox();
    string message = "You scored: " + to_string(score) + "/" + to_string(totalScore);
    box->setWindowTitle("Result");
    box->setText(message.c_str());
    box->exec();

    this->clearAll();
    this->showMenu();
}

void MainWindow::makeDisconnect() {
    QMessageBox *box = new QMessageBox();
    string message = "Unfortunately, you were disconnected from server";
    box->setWindowTitle("Server error");
    box->setText(message.c_str());
    box->exec();

    this->clearAll();
    this->showMenu();
}

void MainWindow::addRadios(vector<string> variants) {
    radioGroup = new QGroupBox("Select answer", this);
    radios.clear();
    QVBoxLayout *layout = new QVBoxLayout(this);
    for (int i = 0; i < (int)variants.size(); i++) {
        QRadioButton *radio = new QRadioButton(QString::fromStdString(variants[i]), this);

        radios.push_back(radio);

        layout->addWidget(radio);
    }
    radioGroup->setLayout(layout);
}
