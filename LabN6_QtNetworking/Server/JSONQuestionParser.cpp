#include <QJsonObject>
#include <QJsonArray>

#include "JSONQuestionParser.h"
#include "Question.h"

JSONQuestionParser::JSONQuestionParser() {}

JSONQuestionParser::~JSONQuestionParser() {}

QJsonObject JSONQuestionParser::toJSON(Question *question) {
    QJsonObject data;
    data.insert("text", QJsonValue::fromVariant(question->getText().c_str()));
    data.insert("variants", toJsonArray(question->getVariants()));

    return data;
}

Question *JSONQuestionParser::toQuestion(QJsonObject *json) {
    return NULL;
}

QJsonArray JSONQuestionParser::toJsonArray(vector<string> variants) {
    QJsonArray result;
    for (int i = 0; i < (int)variants.size(); i++) {
        result.push_back(variants[i].c_str());
    }
    return result;
}
