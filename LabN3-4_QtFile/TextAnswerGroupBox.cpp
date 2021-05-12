#include "QWidget"
#include "QVBoxLayout"
#include "QCheckBox"
#include "QString"

#include "Question.h"

#include "TextAnswerGroupBox.h"

using namespace quiz;

TextAnswerGroupBox::TextAnswerGroupBox(QWidget* widget, Question* question): GroupBox(widget, question) {
    this->widget = widget;
}

void TextAnswerGroupBox::InitWidget() {
    QVBoxLayout* layout = new QVBoxLayout(widget);

    field = new QTextEdit();

    layout->addWidget(field);

    box->setLayout(layout);
}

vector<string> TextAnswerGroupBox::GetUserAnswer() {
    vector<string> answer;
    answer.push_back(field->toPlainText().toUtf8().constData());
    return answer;
}
