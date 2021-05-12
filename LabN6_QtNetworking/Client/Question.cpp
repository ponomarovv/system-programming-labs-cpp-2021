#include <string>
#include <vector>

#include "Question.h"

using namespace std;

Question::Question() {}

Question::Question(string text, vector<string> variants) {
    this->text = text;
    this->variants = variants;
}

Question::~Question() {}

string Question::getText() {
    return this->text;
}

void Question::setText(std::string text) {
    this->text = text;
}

vector<string> Question::getVariants() {
    return this->variants;
}

void Question::setVariants(std::vector<std::string> variants) {
    this->variants = variants;
}
