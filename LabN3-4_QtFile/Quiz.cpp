#include "Quiz.h"
#include "QuestionFactory.h"
#include "DataSource.h"

namespace quiz {

    Quiz::Quiz(DataSource* ds) {
        current = -1;
        totalScore = 0;
        this->ds = ds;
        questionsCount = this->ds->GetQuestionsCount();
        for (int i = 0; i < questionsCount; i++) {
            Question* question = this->ds->GetNextQuestion();
            questions.push_back(question);
            totalScore += question->GetScorePoints();
        }
        this->ds->Finish();
        score = 0;
    }

    bool Quiz::HasNext() {
        return current + 1 < questions.size();
    }

    Question* Quiz::GetCurrectQuestion() {
        return questions[current];
    }

    Question* Quiz::NextQuestion() {
        current++;
        return questions[current];
    }

    void Quiz::CommitAnswer(vector<string> &answer) {
        if (questions[current]->GetType() == "multiple") {
            score += questions[current]->checkResult(answer);
        } else {
            if (answer.size() == 0) {
                score += questions[current]->checkResult("");
            } else {
                score += questions[current]->checkResult(answer[0]);
            }
        }
    }

    int Quiz::GetTotalScore() {
        return totalScore;
    }

    int Quiz::GetScore() {
        return score;
    }

}
