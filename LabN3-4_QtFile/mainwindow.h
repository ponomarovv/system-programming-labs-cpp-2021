#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include <GroupBox.h>
#include <Quiz.h>

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
        void CheckUserAnswer();
        void ShowMenu();
        void ExitApplication();

    private:
        QWidget* mainWidget;
        QPushButton* openButton;
        QPushButton* nextButton;
        QPushButton* mainMenuButton;
        QPushButton* exitButton;
        QLabel* questionText;
        QLabel* currentScore;
        Quiz* quiz;
        QLayout* mainLayout;
        QWidget* widget;
        GroupBox* container;
        void ClearAll();
        void ClearByLayout(QLayout* layout);
        void StartQuiz(string filename);
        void StartMenu();
        void UpdateIndependentElements();
        QWidget* GetNavigationButtons();
};
#endif // MAINWINDOW_H
