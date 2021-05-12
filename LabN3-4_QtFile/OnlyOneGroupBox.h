#ifndef ONLYONEGROUPBOX_H
#define ONLYONEGROUPBOX_H

#include <QWidget>
#include <QRadioButton>

#include <Question.h>
#include <GroupBox.h>

namespace quiz {
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
}

#endif // ONLYONEGROUPBOX_H
