#include "GroupBox.h"

#include <QMainWindow>
#include <QString>
#include <QGroupBox>

using namespace quiz;

namespace quiz {
    GroupBox::GroupBox(QWidget* widget, Question* question) {
        this->question = question;
        box = new QGroupBox(QString::fromStdString("Put your answer here"), widget);
    }

    QGroupBox* GroupBox::GetWidget() {
        this->InitWidget();
        return box;
    }
}
