#include "Specifications.h"

namespace db {

    template <class T>
    Specification<T>::Specification() {}

    template <class T>
    Specification<T>::~Specification() {}

    TypeTitleSpecification::TypeTitleSpecification(string title): Specification<models::Type>() {
        this->title = title;
    }

    TypeTitleSpecification::~TypeTitleSpecification() {}

    bool TypeTitleSpecification::IsSatisfiedBy(models::Type *model) {
        return model->GetTitle() == this->title;
    }

    QuestionQuizIdSpecification::QuestionQuizIdSpecification(int quizId): Specification<models::Question>() {
        this->quizId = quizId;
    }

    QuestionQuizIdSpecification::~QuestionQuizIdSpecification() {}

    bool QuestionQuizIdSpecification::IsSatisfiedBy(models::Question *model) {
        return model->GetQuizId() == this->quizId;
    }

    VariantQuestionIdSpecification::VariantQuestionIdSpecification(int questionId) {
        this->questionId = questionId;
    }

    VariantQuestionIdSpecification::~VariantQuestionIdSpecification() {};

    bool VariantQuestionIdSpecification::IsSatisfiedBy(models::Variant *model) {
        return model->GetQuestionId() == this->questionId;
    }

}
