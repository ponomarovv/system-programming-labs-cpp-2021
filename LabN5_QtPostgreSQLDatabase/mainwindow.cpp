#include "mainwindow.h"
#include <iostream>

#include <QPushButton.h>
#include <QFileDialog.h>
#include <QVBoxLayout>
#include <QLabel>
#include <QApplication>
#include <QMessageBox>

#include "DataSource.h"
#include "Question.h"
#include "GroupBox.h"
#include "Factories.h"

using namespace std;
using namespace quiz;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    quizService = new bl::QuizService();

    setWindowTitle("Db Connection");
    setMinimumSize(400, 400);

    mainWidget = new QWidget();

    setCentralWidget(mainWidget);

    StartMenu();

}

MainWindow::~MainWindow()
{
}

void MainWindow::StartMenu() {
    mainLayout = new QVBoxLayout(this);

    openButton = new QPushButton("Open", this);
    exitButton = new QPushButton("Exit", this);

    this->InitQuizListWidget();

    mainLayout->addWidget(listWidget);
    mainLayout->addWidget(openButton);
    mainLayout->addWidget(exitButton);

    connect(openButton, SIGNAL(released()), this, SLOT(LoadQuiz()));
    connect(exitButton, SIGNAL(released()), this, SLOT(ExitApplication()));

    mainWidget->setLayout(mainLayout);
}

void MainWindow::InitQuizListWidget() {
    listWidget = new QListWidget(this);
    quizzes = quizService->GetAll();
    for (int i = 0; i < quizzes.size(); i++) {
        QListWidgetItem* item = new QListWidgetItem();
        item->setText(QString::fromStdString(quizzes[i]->GetTitle()));
        listWidget->insertItem(i, item);
    }
}

void MainWindow::UpdateLayout(QWidget* toReplace) {
    Question* question = quiz->NextQuestion();
    UpdateIndependentElements();
    questionText->setText(QString::fromStdString(question->GetText() + "(" + to_string(question->GetScorePoints()) + " points)"));
    container = GroupBoxFactory::GetByQuestion(this, question);
    mainLayout->replaceWidget(toReplace, container->GetWidget());
    delete toReplace;
}

void MainWindow::CheckUserAnswer() {
    vector<string> answer = container->GetUserAnswer();
    quiz->CommitAnswer(answer);
    if (quiz->HasNext()) {
        UpdateLayout(container->GetWidget());
    } else {
        nextButton->setEnabled(false);
        int score = quiz->GetScore();
        QMessageBox* box = new QMessageBox();
        string message = "Кількість набраних Вами балів: " + to_string(score) + "/" + to_string(quiz->GetTotalScore());
        box->setWindowTitle("Оцінка");
        box->setText(message.c_str());
        UpdateIndependentElements();
        box->exec();
    }
}

void MainWindow::UpdateIndependentElements() {
    currentScore->setText(QString::fromStdString("Бали: " + to_string(quiz->GetScore())));
}

void MainWindow::LoadQuiz() {
    int selected = listWidget->currentRow();
    if (selected == -1) {
        QMessageBox* box = new QMessageBox();
        string message = "Спочатку оберіть тест";
        box->setWindowTitle("Помилка");
        box->setText(message.c_str());
        box->exec();
        return;
    }
    quiz = quizService->GetFullQuiz(quizzes[selected]);
    ClearAll();
    StartQuiz();
}

void MainWindow::OpenFile() {
    QString qFilename = QFileDialog::getOpenFileName(this, tr("Open Test File"), "", tr("Text Files (*.txt)"));
    string filename = qFilename.toUtf8().constData();
    if (filename != "") {
        ClearAll();
        const char* filepath = filename.c_str();
        quiz = new Quiz(new FileDataSource(filepath));
        StartQuiz();
    }
}

void MainWindow::ClearAll() {
    ClearByLayout(mainLayout);
}

void MainWindow::ClearByLayout(QLayout* layout) {
    QLayoutItem* item;
    while ((item = layout->takeAt(0))) {
        if (item->layout()) {
            ClearByLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
    delete layout;
}

void MainWindow::StartQuiz() {
    widget = new QWidget();
    mainLayout = new QVBoxLayout(this);

    currentScore = new QLabel("", this);
    currentScore->setWordWrap(true);
    currentScore->setAlignment(Qt::AlignRight);

    questionText = new QLabel("", this);
    questionText->setWordWrap(true);

    mainLayout->addWidget(currentScore);
    mainLayout->addWidget(questionText);
    mainLayout->addWidget(widget);
    mainLayout->addWidget(GetNavigationButtons());

    mainWidget->setLayout(mainLayout);

    UpdateLayout(widget);
}

QWidget* MainWindow::GetNavigationButtons() {
    QWidget* navigationWidget = new QWidget();
    QLayout* layout = new QHBoxLayout();
    mainMenuButton = new QPushButton("Main Menu", this);
    nextButton = new QPushButton("Next", this);
    layout->addWidget(mainMenuButton);
    layout->addWidget(nextButton);

    connect(nextButton, SIGNAL(released()), this, SLOT(CheckUserAnswer()));
    connect(mainMenuButton, SIGNAL(released()), this, SLOT(ShowMenu()));

    navigationWidget->setLayout(layout);
    return navigationWidget;
}

void MainWindow::ShowMenu() {
    ClearAll();
    StartMenu();
}

void MainWindow::ExitApplication() {
    QApplication::exit();
}
