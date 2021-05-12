#ifndef REPOSITORIES_H
#define REPOSITORIES_H

#include <vector>
#include <string>
#include "Specifications.h"
#include "SqlQueryParsers.h"
#include "Models.h"

using namespace std;

namespace db {

    template <class T>
    class Repository {
        public:
            Repository();
            ~Repository();

            virtual void Create(T* model) = 0;
            virtual T* Read(int id);
            virtual void Update(int id, T* model) = 0;
            virtual void Delete(int id);
            virtual vector<T*> ReadByQuery(Specification<T>* specification);
            virtual vector<T*> ReadAll();

        protected:
            void Init(); // must be called in constructor
            virtual string GetTableName() = 0;
            virtual SqlQueryParser<T>* GetSqlQueryParser() = 0;
            string tableName;
            SqlQueryParser<T>* parser;
    };

    class TypeRepository: public Repository<models::Type> {
        public:
            TypeRepository();
            ~TypeRepository();
            void Create(models::Type* model);
            void Update(int id, models::Type* model);

        protected:
            string GetTableName();
            SqlQueryParser<models::Type>* GetSqlQueryParser();
    };

    class QuestionRepository: public Repository<models::Question> {
        public:
            QuestionRepository();
            ~QuestionRepository();
            void Create(models::Question* model);
            void Update(int id, models::Question* model);

        protected:
            string GetTableName();
            SqlQueryParser<models::Question>* GetSqlQueryParser();
    };

    class QuizRepository: public Repository<models::Quiz> {
        public:
            QuizRepository();
            ~QuizRepository();
            void Create(models::Quiz* model);
            void Update(int id, models::Quiz* model);

        protected:
            string GetTableName();
            SqlQueryParser<models::Quiz>* GetSqlQueryParser();
    };

    class VariantRepository: public Repository<models::Variant> {
        public:
            VariantRepository();
            ~VariantRepository();
            void Create(models::Variant* model);
            void Update(int id, models::Variant* model);

        protected:
            string GetTableName();
            SqlQueryParser<models::Variant>* GetSqlQueryParser();
    };

}

#endif // REPOSITORIES_H
