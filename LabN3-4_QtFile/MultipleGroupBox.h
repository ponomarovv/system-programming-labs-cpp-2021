#ifndef MULTIPLEGROUPBOX_H
#define MULTIPLEGROUPBOX_H

#include <QWidget>
#include <QCheckBox>

#include <Question.h>
#include <GroupBox.h>

namespace quiz {
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
}

#endif // MULTIPLEGROUPBOX_H
