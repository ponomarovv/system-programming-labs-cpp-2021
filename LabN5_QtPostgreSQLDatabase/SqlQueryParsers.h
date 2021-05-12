#ifndef SQLQUERYPARSERS_H
#define SQLQUERYPARSERS_H

#include <QSqlQuery>
#include "Models.h"

namespace db {

    template <class T>
    class SqlQueryParser {
        public:
            SqlQueryParser();
            ~SqlQueryParser();
            virtual T* Parse(QSqlQuery* query) = 0;
    };

    class TypeSqlParser: public SqlQueryParser<models::Type> {
        public:
            TypeSqlParser();
            ~TypeSqlParser();
            models::Type* Parse(QSqlQuery* query);
    };

    class QuestionSqlParser: public SqlQueryParser<models::Question> {
        public:
            QuestionSqlParser();
            ~QuestionSqlParser();
            models::Question* Parse(QSqlQuery* query);
    };

    class QuizSqlParser: public SqlQueryParser<models::Quiz> {
        public:
            QuizSqlParser();
            ~QuizSqlParser();
            models::Quiz* Parse(QSqlQuery* query);
    };

    class VariantSqlParser: public SqlQueryParser<models::Variant> {
        public:
            VariantSqlParser();
            ~VariantSqlParser();
            models::Variant* Parse(QSqlQuery* query);
    };

}

#endif // SQLQUERYPARSERS_H
