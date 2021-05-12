#ifndef SPECIFICATIONS_H
#define SPECIFICATIONS_H

#include "Models.h"

namespace db {

    template <class T>
    class Specification {
        public:
            Specification();
            ~Specification();
            virtual bool IsSatisfiedBy(T* model) = 0;
    };

    class TypeTitleSpecification: public Specification<models::Type> {
        public:
            TypeTitleSpecification(string title);
            ~TypeTitleSpecification();
            bool IsSatisfiedBy(models::Type *model);

        private:
            string title;
    };

    class QuestionQuizIdSpecification: public Specification<models::Question> {
        public:
            QuestionQuizIdSpecification(int quizId);
            ~QuestionQuizIdSpecification();
            bool IsSatisfiedBy(models::Question* model);

        private:
            int quizId;
    };

    class VariantQuestionIdSpecification: public Specification<models::Variant> {
        public:
            VariantQuestionIdSpecification(int questionId);
            ~VariantQuestionIdSpecification();
            bool IsSatisfiedBy(models::Variant* model);

        private:
            int questionId;
    };

}

#endif // SPECIFICATIONS_H
