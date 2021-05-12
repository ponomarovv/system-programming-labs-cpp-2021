#ifndef SERVICES_H
#define SERVICES_H

#include "Repositories.h"
#include "Models.h"
#include "Quiz.h"

namespace bl {

    template <class T>
    class Service {
        public:
            Service();
            ~Service();
            virtual vector<T*> GetAll();

        protected:
            void Init(); // must be called in constructor of derived class
            virtual db::Repository<T>* GetRepository() = 0;
            db::Repository<T>* repository;
    };

    class QuizService: public Service<models::Quiz> {
        public:
            QuizService();
            ~QuizService();
            quiz::Quiz* GetFullQuiz(models::Quiz* quiz);

        protected:
            virtual db::Repository<models::Quiz>* GetRepository();
    };

    class QuestionService: public Service<models::Question> {
        public:
            QuestionService();
            ~QuestionService();
            vector<models::Question*> GetQuestionsByQuiz(models::Quiz* quiz);
            quiz::Question* GetQuizQuestion(models::Question* question);

        protected:
            db::Repository<models::Question>* GetRepository();

        private:
            map<int, models::Type*> types;
            vector<models::Variant*> GetVariants(models::Question* question);
    };

}

#endif // SERVICES_H
