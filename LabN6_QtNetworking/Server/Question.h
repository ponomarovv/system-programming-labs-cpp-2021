#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

using namespace std;

class Question {
    public:
        Question(string text, vector<string> variants, int correct, int score);
        ~Question();

        bool isCorrect(int correct);

        string getText();
        void setText(string text);

        vector<string> getVariants();
        void setVariants(vector<string> variants);

        int getCorrect();
        void setCorrect(int correct);

        int getScore();
        void setScore(int score);

    private:
        string text;
        vector<string> variants;
        int correct;
        int score;
};

#endif // QUESTION_H
