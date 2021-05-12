#include <QSqlQuery>

#include "SqlQueryParsers.h"
#include "Models.h"

namespace db {

    template <class T>
    SqlQueryParser<T>::SqlQueryParser() {}

    template <class T>
    SqlQueryParser<T>::~SqlQueryParser() {}

    TypeSqlParser::TypeSqlParser() {}

    TypeSqlParser::~TypeSqlParser() {}

    models::Type* TypeSqlParser::Parse(QSqlQuery* query) {
        int id = query->value(0).toInt();
        string title = query->value(1).toString().toUtf8().constData();

        models::Type* type = new models::Type();
        type->SetId(id);
        type->SetTitle(title);

        return type;
    }

    QuestionSqlParser::QuestionSqlParser() {}

    QuestionSqlParser::~QuestionSqlParser() {}

    models::Question* QuestionSqlParser::Parse(QSqlQuery* query) {
        int id = query->value(0).toInt();
        string title = query->value(1).toString().toUtf8().constData();
        int typeId = query->value(2).toInt();
        int quizId = query->value(3).toInt();
        int score = query->value(4).toInt();

        models::Question* question = new models::Question();
        question->SetId(id);
        question->SetTitle(title);
        question->SetTypeId(typeId);
        question->SetQuizId(quizId);
        question->SetScore(score);

        return question;
    }

    QuizSqlParser::QuizSqlParser() {}

    QuizSqlParser::~QuizSqlParser() {}

    models::Quiz* QuizSqlParser::Parse(QSqlQuery* query) {
        int id = query->value(0).toInt();
        string title = query->value(1).toString().toUtf8().constData();

        models::Quiz* quiz = new models::Quiz();
        quiz->SetId(id);
        quiz->SetTitle(title);

        return quiz;
    }

    VariantSqlParser::VariantSqlParser() {}

    VariantSqlParser::~VariantSqlParser() {}

    models::Variant* VariantSqlParser::Parse(QSqlQuery* query) {
        int id = query->value(0).toInt();
        int questionId = query->value(1).toInt();
        string variantText = query->value(2).toString().toUtf8().constData();
        bool isAnswer = query->value(3).toBool();

        models::Variant* variant = new models::Variant();
        variant->SetId(id);
        variant->SetQuestionId(questionId);
        variant->SetVariant(variantText);
        variant->SetIsAnswer(isAnswer);

        return variant;
    }

}
