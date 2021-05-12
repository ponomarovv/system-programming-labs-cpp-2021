#include <QJsonArray>

#include <string>

#include "JSONQuestionParser.h"
#include "Question.h"

using namespace std;

JSONQuestionParser::JSONQuestionParser() {}
JSONQuestionParser::~JSONQuestionParser() {}

Question *JSONQuestionParser::toQuestion(QJsonObject json) {
    Question *question = new Question();

    vector<string> variants;

    QJsonArray jsonVariants = json.value("variants").toArray();

    foreach (const QJsonValue value, jsonVariants) {
        variants.push_back(value.toString().toStdString());
    }

    question->setText(json.value("text").toVariant().toString().toStdString());
    question->setVariants(variants);


    return question;
}
