#include "QWidget"
#include "QVBoxLayout"
#include "QCheckBox"
#include "QString"

#include "Question.h"

#include "GroupBox.h"

namespace quiz {
    OnlyOneGroupBox::OnlyOneGroupBox(QWidget* widget, Question* question): GroupBox(widget, question) {
        this->widget = widget;
    }

    void OnlyOneGroupBox::InitWidget() {
        QVBoxLayout* layout = new QVBoxLayout(widget);
        for (int i = 0; i < question->GetOptions().size(); i++) {
            string option = question->GetOptions()[i];
            QRadioButton* radio = new QRadioButton(QString::fromStdString(option), widget);
            options.push_back(radio);
            layout->addWidget(radio);
        }
        box->setLayout(layout);
    }

    vector<string> OnlyOneGroupBox::GetUserAnswer() {
        vector<string> answer;
        for (int i = 0; i < question->GetOptions().size(); i++) {
            string option = question->GetOptions()[i];
            //cout << "options: " << option << endl;
            QRadioButton* radio = options[i];
            if (radio->isChecked()) {
                answer.push_back(option);
            }
        }
        return answer;
    }
}
