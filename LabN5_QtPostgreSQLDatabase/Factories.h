#ifndef FACTORIES_H
#define FACTORIES_H

#include "GroupBox.h"
#include "Question.h"

namespace quiz {
    class GroupBoxFactory {

        public:
            static GroupBox* GetByQuestion(QWidget* widget, Question* question);

        private:
            GroupBoxFactory();
    };

    class QuestionFactory
    {
        public:
            static Question* CreateMultipleQuestion(string text, const vector<string> &options, const vector<string> &answers, int score);
            static Question* CreateOneCorrectQuestion(string text, const vector<string> &options, string correct, int score);
            static Question* CreateTextQuestion(string text, string answer, int score);
    };
}

#endif // FACTORIES_H
