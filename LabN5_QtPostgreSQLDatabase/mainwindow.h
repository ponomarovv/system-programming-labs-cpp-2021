#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <GroupBox.h>

#include "Quiz.h"
#include "Services.h"
#include "Models.h"

using namespace quiz;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void UpdateLayout(QWidget* toReplace);
        void OpenFile();
        void LoadQuiz();
        void CheckUserAnswer();
        void ShowMenu();
        void ExitApplication();

    private:
        QWidget* mainWidget;
        QPushButton* openButton;
        QPushButton* nextButton;
        QPushButton* mainMenuButton;
        QPushButton* exitButton;
        QListWidget* listWidget;
        QLabel* questionText;
        QLabel* currentScore;
        Quiz* quiz;
        QLayout* mainLayout;
        QWidget* widget;
        GroupBox* container;
        vector<QListWidgetItem*> listItems;
        vector<models::Quiz*> quizzes;

        bl::QuizService* quizService;

        void ClearAll();
        void ClearByLayout(QLayout* layout);
        void StartQuiz();
        void StartMenu();
        void UpdateIndependentElements();
        QWidget* GetNavigationButtons();
        void InitQuizListWidget();
};
#endif // MAINWINDOW_H
