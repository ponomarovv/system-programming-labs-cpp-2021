#ifndef GROUPBOX_H
#define GROUPBOX_H

#include <QWidget>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QTextEdit>

#include "Question.h"

using namespace quiz;

namespace quiz {
    class GroupBox {

        public:
            GroupBox(QWidget* window, Question* question);
            ~GroupBox();
            QGroupBox* GetWidget();
            virtual vector<string> GetUserAnswer() = 0;

        protected:
            Question* question;
            QGroupBox* box;

            virtual void InitWidget() = 0;

    };

    class MultipleGroupBox: public GroupBox {

        public:
            MultipleGroupBox(QWidget* widget, Question* question);
            ~MultipleGroupBox();
            vector<string> GetUserAnswer();

        protected:
            virtual void InitWidget();

        private:
            vector<QCheckBox*> options;
            QWidget* widget;

    };

    class OnlyOneGroupBox: public GroupBox {

        public:
            OnlyOneGroupBox(QWidget* widget, Question* question);
            ~OnlyOneGroupBox();
            vector<string> GetUserAnswer();

        protected:
            virtual void InitWidget();

        private:
            vector<QRadioButton*> options;
            QWidget* widget;

    };

    class TextAnswerGroupBox: public GroupBox {

        public:
            TextAnswerGroupBox(QWidget* widget, Question* question);
            ~TextAnswerGroupBox();
            vector<string> GetUserAnswer();

        protected:
            virtual void InitWidget();

        private:
            QTextEdit* field;
            QWidget* widget;

    };
}

#endif // GROUPBOX_H
