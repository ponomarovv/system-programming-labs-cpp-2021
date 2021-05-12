#ifndef QUIZ_H
#define QUIZ_H

#include "Question.h"

class Quiz {
    public:
        Quiz();
        ~Quiz();
        bool hasNext();
        Question *getNextQuestion();
        int getCurrentScore();
        int getTotalScore();
        Question* getCurrentQuestion();
        void checkAnswer(int selected);

    private:
        int currentIndex;
        int currentScore;
        int totalScore;
        vector<Question*> questions;

};

#endif // QUIZ_H
