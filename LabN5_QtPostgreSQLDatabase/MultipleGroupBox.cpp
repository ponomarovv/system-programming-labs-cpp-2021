#include "GroupBox.h"

#include "QWidget"
#include "QVBoxLayout"
#include "QCheckBox"
#include "QString"

#include "Question.h"

namespace quiz {
    MultipleGroupBox::MultipleGroupBox(QWidget* widget, Question* question): GroupBox(widget, question) {
        this->widget = widget;
    }

    void MultipleGroupBox::InitWidget() {
        QVBoxLayout* layout = new QVBoxLayout(widget);
        for (int i = 0; i < question->GetOptions().size(); i++) {
            string option = question->GetOptions()[i];
            QCheckBox* check = new QCheckBox(QString::fromStdString(option), widget);
            options.push_back(check);
            layout->addWidget(check);
        }
        box->setLayout(layout);
    }

    vector<string> MultipleGroupBox::GetUserAnswer() {
        vector<string> answer;
        for (int i = 0; i < question->GetOptions().size(); i++) {
            string option = question->GetOptions()[i];
            QCheckBox* check = options[i];
            if (check->isChecked()) {
                answer.push_back(option);
            }
        }
        return answer;
    }
}
