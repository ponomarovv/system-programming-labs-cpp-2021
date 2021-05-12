#ifndef GROUPBOX_H
#define GROUPBOX_H

#include <QWidget>
#include <QGroupBox>

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
}

#endif // GROUPBOX_H
