#ifndef TEXTANSWERGROUPBOX_H
#define TEXTANSWERGROUPBOX_H

#include <QWidget>
#include <QTextEdit>

#include <Question.h>
#include <GroupBox.h>

namespace quiz {
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

#endif
