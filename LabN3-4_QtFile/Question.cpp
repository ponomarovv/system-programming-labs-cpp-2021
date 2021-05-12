#include "Question.h"

#include <vector>
#include <iostream>
#include <string>
using namespace std;


namespace  quiz
{
    Question::Question()
    {
        text = type = "";
    };

    string Question::GetText()
    {
        return text;
    }
    void Question::SetText(string text)
    {
        this->text = text;
    }


    string Question::GetType()
    {
        return type;
    }
    void Question::SetType(string text)
    {
        this->type = text;
    }

    vector<string> Question::GetOptions()
    {
        return options;
    }
    void Question::SetOptions(vector<string> options)
    {
        this->options = options;
    }

    vector<string> Question::GetAnswers()
    {
        return answers;
    }
    void Question::SetAnswers(vector<string> answers)
    {
        this->answers = answers;
    }

    string Question::GetCorrectAnswer()
    {
        return correctAnswer;
    }
    void Question::SetCorrectAnswer(string correctAnswer)
    {
        this->correctAnswer = correctAnswer;
    }


    int Question::GetScorePoints ()
    {
        return scorePoints;
    }
    void Question::SetScorePoints(int scorePoints)
    {
        this->scorePoints = scorePoints;
    }




    int Question::checkResult(vector<string> selected)
    {
        int correct = 0;
        int answers_length = answers.size();
        int selected_length = selected.size();
        for(int i = 0; i < answers_length; i++) // answers length
        {
            for(int j = 0; j < selected_length; j++) // selected length
            {
                if (answers[i] == selected[j])
                {
                    correct++;
                }
            }
        }


        if (correct == answers_length && correct == selected_length)
        {
            return scorePoints;
        }
        return 0;
    }

    int Question::checkResult(string answer)
    {
        if (answer == correctAnswer) {
            return scorePoints;
        }
        return 0;
    }



    Question::Builder::Builder()
    {
        question = new Question();
    }

    Question::Builder* Question::Builder::SetOptions(vector<string> options) {
        // Throw an error if kind is a text-field
        question->SetOptions(options);

        return this;
    }

    Question::Builder* Question::Builder::SetAnswers(vector<string> answers) {
        // Throw an error if kind is a text-field or non-multiple
        question->SetAnswers(answers);

        return this;
    }

    Question::Builder* Question::Builder::SetCorrectAnswer(string correctAnswer) {
        // Throw an error if kind is not a text-field
        question->SetCorrectAnswer(correctAnswer);

        return this;
    }

    Question::Builder* Question::Builder::SetScorePoints(int scorePoints) {
        question->scorePoints = scorePoints;

        return this;
    }

    Question* Question::Builder::Build() {
        return question;
    }

    Question::Builder* Question::Builder::SetText(string text)
    {
        question->SetText(text);

        return this;
    }



    Question::Builder* Question::Builder::SetType(string type)
    {
        question->SetType(type);

        return this;
    }


}
