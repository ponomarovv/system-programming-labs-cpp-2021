#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;


namespace  quiz
{
    class Question
    {
        public:
            int checkResult(vector<string> selected);
            int checkResult(string answer);

            string GetText();
            void SetText(string text);

            string GetType();
            void SetType(string text);

            vector<string> GetOptions();
            void SetOptions(vector<string> options);

            vector<string> GetAnswers();
            void SetAnswers(vector<string> answers);

            string GetCorrectAnswer();
            void SetCorrectAnswer(string correctAnswer);


            int GetScorePoints ();
            void SetScorePoints(int scorePoints);


            // builder begin
            class Builder
            {

            public:
                Builder();

                Builder* SetText(string text);

                Builder* SetType(string type);



                Builder* SetOptions(vector<string> options);

                Builder* SetAnswers(vector<string> answers);

                Builder* SetCorrectAnswer(string correctAnswer);

                Builder* SetScorePoints(int scorePoints);

                Question* Build();

            private:
                Question* question;
            };
            // end of class Builder


        private:
            string text;
            string type; // multiple, non-multiple, text-field

            vector<string> options;
            vector<string> answers;

            string correctAnswer;  // If text-field

            int scorePoints; // for this question.

            Question();
            ~Question();

    };

}
#endif // QUESTION_H
