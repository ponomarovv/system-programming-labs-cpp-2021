#include "Factories.h"
#include "Question.h"

namespace quiz {

    Question* QuestionFactory::CreateMultipleQuestion(string text, const vector<string> &options, const vector<string> &answers, int score) {
        Question::Builder* builder = new Question::Builder();
        return builder->SetType("multiple")
                ->SetText(text)
                ->SetOptions(options)
                ->SetAnswers(answers)
                ->SetScorePoints(score)
                ->Build();
    }

    Question* QuestionFactory::CreateOneCorrectQuestion(string text, const vector<string> &options, string correct, int score) {
        Question::Builder* builder = new Question::Builder();
        return builder->SetType("non-multiple")
                ->SetText(text)
                ->SetOptions(options)
                ->SetCorrectAnswer(correct)
                ->SetScorePoints(score)
                ->Build();
    }

    Question* QuestionFactory::CreateTextQuestion(string text, string answer, int score) {
        Question::Builder* builder = new Question::Builder();
        return builder->SetType("text-field")
                ->SetText(text)
                ->SetCorrectAnswer(answer)
                ->SetScorePoints(score)
                ->Build();
    }

}
