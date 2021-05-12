#ifndef QUESTIONFACTORY_H
#define QUESTIONFACTORY_H

#include "Question.h"

namespace  quiz
{
    class QuestionFactory
    {
        public:
            static Question* CreateMultipleQuestion(string text, const vector<string> &options, const vector<string> &answers, int score);
            static Question* CreateOneCorrectQuestion(string text, const vector<string> &options, string correct, int score);
            static Question* CreateTextQuestion(string text, string answer, int score);
    };
}

#endif // QUESTIONFACTORY_H
