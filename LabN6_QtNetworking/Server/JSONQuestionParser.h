#ifndef JSONQUESTIONPARSER_H
#define JSONQUESTIONPARSER_H

#include <QJsonObject>

#include "Question.h"

class JSONQuestionParser {
    public:
        JSONQuestionParser();
        ~JSONQuestionParser();
        QJsonObject toJSON(Question* question);
        Question* toQuestion(QJsonObject* json);

    private:
        QJsonArray toJsonArray(vector<string> variants);
};

#endif // JSONQUESTIONPARSER_H
