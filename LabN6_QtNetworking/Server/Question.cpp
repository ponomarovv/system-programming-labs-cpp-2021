#include <string>

#include "Question.h"

using namespace std;

Question::Question(string text, vector<string> variants, int correct, int score) {
    this->text = text;
    this->variants = variants;
    this->correct = correct;
    this->score = score;
}

Question::~Question() {}

bool Question::isCorrect(int correct) {
    return this->correct == correct;
}

string Question::getText() {
    return this->text;
}

void Question::setText(string text) {
    this->text = text;
}

vector<string> Question::getVariants() {
    return this->variants;
}

void Question::setVariants(vector<string> variants) {
    this->variants = variants;
}

int Question::getCorrect() {
    return this->correct;
}

void Question::setCorrect(int correct) {
    this->correct = correct;
}

int Question::getScore() {
    return this->score;
}

void Question::setScore(int score) {
    this->score = score;
}
