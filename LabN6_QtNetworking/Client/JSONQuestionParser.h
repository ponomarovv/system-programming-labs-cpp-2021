#ifndef JSONQUESTIONPARSER_H
#define JSONQUESTIONPARSER_H

#include <QJsonObject>

#include "Question.h"

class JSONQuestionParser {
    public:
        JSONQuestionParser();
        ~JSONQuestionParser();
        Question *toQuestion(QJsonObject json);
};

#endif // JSONQUESTIONPARSER_H
