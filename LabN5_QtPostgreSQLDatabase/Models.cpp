#include "Models.h"

namespace models {

    /*  Type Model  */
    Type::Type() {}

    Type::~Type() {}

    int Type::GetId() {
        return this->id;
    }

    void Type::SetId(int id) {
        this->id = id;
    }

    string Type::GetTitle() {
        return this->title;
    }

    void Type::SetTitle(string title) {
        this->title = title;
    }

    /*  Quiz Model  */
    Quiz::Quiz() {}

    Quiz::~Quiz() {}

    int Quiz::GetId() {
        return this->id;
    }

    void Quiz::SetId(int id) {
        this->id = id;
    }

    string Quiz::GetTitle() {
        return this->title;
    }

    void Quiz::SetTitle(string title) {
        this->title = title;
    }

    /*  Question Model  */
    Question::Question() {}

    Question::~Question() {}

    int Question::GetId() {
        return this->id;
    }

    void Question::SetId(int id) {
        this->id = id;
    }

    string Question::GetTitle() {
        return this->title;
    }

    void Question::SetTitle(string title) {
        this->title = title;
    }

    int Question::GetTypeId() {
        return this->typeId;
    }

    void Question::SetTypeId(int typeId) {
        this->typeId = typeId;
    }

    int Question::GetQuizId() {
        return this->quizId;
    }

    void Question::SetQuizId(int quizId) {
        this->quizId = quizId;
    }

    int Question::GetScore() {
        return this->score;
    }

    void Question::SetScore(int score) {
        this->score = score;
    }

    /*  Variant Model  */
    Variant::Variant() {}

    Variant::~Variant() {}

    int Variant::GetId() {
        return this->id;
    }

    void Variant::SetId(int id) {
        this->id = id;
    }

    int Variant::GetQuestionId() {
        return this->questionId;
    }

    void Variant::SetQuestionId(int questionId) {
        this->questionId = questionId;
    }

    string Variant::GetVariant() {
        return this->variant;
    }

    void Variant::SetVariant(string variant) {
        this->variant = variant;
    }

    bool Variant::GetIsAnswer() {
        return this->isAnswer;
    }

    void Variant::SetIsAnswer(bool isAnswer) {
        this->isAnswer = isAnswer;
    }

}
