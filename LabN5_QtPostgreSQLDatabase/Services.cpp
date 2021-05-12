#include "Services.h"
#include "Repositories.h"
#include "SqlQueryParsers.h"
#include "Specifications.h"
#include "Factories.h"

#include <QMessageBox>

namespace bl {

    template <class T>
    Service<T>::Service() {}

    template <class T>
    Service<T>::~Service() {}

    template <class T>
    void Service<T>::Init() {
        this->repository = GetRepository();
    }

    template <class T>
    vector<T*> Service<T>::GetAll() {
        return this->repository->ReadAll();
    }

    QuizService::QuizService(): Service<models::Quiz>() {
        this->Init();
    }

    QuizService::~QuizService() {}

    db::Repository<models::Quiz>* QuizService::GetRepository() {
        return new db::QuizRepository();
    }

    quiz::Quiz* QuizService::GetFullQuiz(models::Quiz *quiz) {
        QuestionService* service = new QuestionService();
        vector<models::Question*> questions = service->GetQuestionsByQuiz(quiz);
        vector<quiz::Question*> quizQuestions;
        for (int i = 0; i < questions.size(); i++) {
            quizQuestions.push_back(service->GetQuizQuestion(questions[i]));
        }
        return new quiz::Quiz(quizQuestions);
    }

    QuestionService::QuestionService(): Service<models::Question>() {
        this->Init();
        db::Repository<models::Type>* typeRepository = new db::TypeRepository();
        vector<models::Type*> _types = typeRepository->ReadAll();
        for (int i = 0; i < _types.size(); i++) {
            this->types[_types[i]->GetId()] = _types[i];
        }
    }

    QuestionService::~QuestionService() {}

    db::Repository<models::Question>* QuestionService::GetRepository() {
        return new db::QuestionRepository();
    }

    vector<models::Question*> QuestionService::GetQuestionsByQuiz(models::Quiz* quiz) {
        db::Specification<models::Question>* specification = new db::QuestionQuizIdSpecification(quiz->GetId());
        return this->repository->ReadByQuery(specification);
    }

    quiz::Question* QuestionService::GetQuizQuestion(models::Question* question) {
        models::Type* type = this->types[question->GetTypeId()];
        vector<models::Variant*> _variants = GetVariants(question);
        vector<string> variants;
        vector<string> answers;
        for (int i = 0; i < _variants.size(); i++) {
            variants.push_back(_variants[i]->GetVariant());
            if (_variants[i]->GetIsAnswer()) {
                answers.push_back(_variants[i]->GetVariant());
            }
        }

        QuestionFactory* factory = new QuestionFactory();

        if (type->GetTitle() == "multiple") {
            return factory->CreateMultipleQuestion(
                        question->GetTitle(),
                        variants,
                        answers,
                        question->GetScore());
        } else if (type->GetTitle() == "non-multiple") {
            return factory->CreateOneCorrectQuestion(
                        question->GetTitle(),
                        variants,
                        answers.size() == 0 ? variants[0] : answers[0],
                        question->GetScore());
        } else if (type->GetTitle() == "text-field") {
            return factory->CreateTextQuestion(
                        question->GetTitle(),
                        variants[0],
                        question->GetScore());
        }

        return NULL;
    }

    vector<models::Variant*> QuestionService::GetVariants(models::Question* question) {
        db::Repository<models::Variant>* variantRepository = new db::VariantRepository();
        db::Specification<models::Variant>* variantSpecification = new db::VariantQuestionIdSpecification(question->GetId());
        return variantRepository->ReadByQuery(variantSpecification);
    }

}
