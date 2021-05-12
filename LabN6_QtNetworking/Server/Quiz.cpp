#include <string>
#include <vector>

#include "Question.h"
#include "Quiz.h"

using namespace std;

Quiz::Quiz() {
    this->currentIndex = -1;
    questions.push_back(new Question(
        "Does FICT exist?",
        vector<string> {"Yes", "No"},
        1,
        5
    ));
    questions.push_back(new Question(
        "Choose programming language",
        vector<string> {"HTML", "CSS", "Java"},
        2,
        10
    ));
    questions.push_back(new Question(
        "It's 1-score question just for fun",
        vector<string> {"Not this", "And not this", "This one is correct", "Too far"},
        2,
        1
    ));

    this->currentScore = 0;
    this->totalScore = 0;
    for (int i = 0; i < (int)questions.size(); i++) {
        this->totalScore += questions[i]->getScore();
    }
}

Quiz::~Quiz() {}

bool Quiz::hasNext() {
    return this->currentIndex + 1 < (int)this->questions.size();
}

Question *Quiz::getNextQuestion() {
    this->currentIndex++;
    return this->questions[currentIndex];
}

int Quiz::getCurrentScore() {
    return this->currentScore;
}

int Quiz::getTotalScore() {
    return this->totalScore;
}

Question *Quiz::getCurrentQuestion() {
    return this->questions[this->currentIndex];
}

void Quiz::checkAnswer(int selected) {
    this->currentScore += getCurrentQuestion()->isCorrect(selected) ? getCurrentQuestion()->getScore() : 0;
}
