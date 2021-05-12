#include "Repositories.h"
#include "SqlQueryParsers.h"

namespace db {

    template <class T>
    Repository<T>::Repository() {};

    template <class T>
    Repository<T>::~Repository() {}

    template <class T>
    void Repository<T>::Init() {
        this->tableName = GetTableName();
        this->parser = GetSqlQueryParser();
    }

    template <class T>
    T* Repository<T>::Read(int id) {
        QSqlQuery* query = new QSqlQuery();
        query->prepare("SELECT * FROM \":tableName\" WHERE id=:id");
        query->bindValue(":tableName", this->tableName.c_str());
        query->bindValue(":id", id);
        query->exec();
        if (query->next()) {
            return parser->Parse(query);
        }
        return NULL;
    }

    template <class T>
    void Repository<T>::Delete(int id) {
        QSqlQuery* query = new QSqlQuery();
        query->prepare("DELETE FROM \"" + QString::fromStdString(this->tableName) + "\" WHERE id=:id");
        query->bindValue(":id", id);
        query->exec();
    }

    template <class T>
    vector<T*> Repository<T>::ReadByQuery(Specification<T>* specification) {
        vector<T*> all = ReadAll();
        vector<T*> answer;
        for (int i = 0; i < all.size(); i++) {
            if (specification->IsSatisfiedBy(all[i])) {
                answer.push_back(all[i]);
            }
        }
        return answer;
    }

    template <class T>
    vector<T*> Repository<T>::ReadAll() {
        vector<T*> answer;
        QSqlQuery* query = new QSqlQuery();
        query->exec("SELECT * FROM \"" + QString::fromStdString(this->tableName) + "\" ORDER BY id ASC");
        while (query->next()) {
            T* model = parser->Parse(query);
            answer.push_back(model);
        }
        return answer;
    }

    TypeRepository::TypeRepository(): Repository<models::Type>() {
        this->Init();
    }

    string TypeRepository::GetTableName() {
        return "Types";
    }

    SqlQueryParser<models::Type>* TypeRepository::GetSqlQueryParser() {
        return new TypeSqlParser();
    }

    void TypeRepository::Create(models::Type* model) {
        QSqlQuery* query = new QSqlQuery();
        query->prepare("INSERT INTO \"" + QString::fromStdString(this->tableName) + "\" (id, title) VALUES (:id, :title)");
        query->bindValue(":id", model->GetId());
        query->bindValue(":title", QString::fromStdString(model->GetTitle()));
        query->exec();
    }

    void TypeRepository::Update(int id, models::Type* model) {
        QSqlQuery* query = new QSqlQuery();
        query->prepare("UPDATE \"" + QString::fromStdString(this->tableName) + "\" SET title=:title WHERE id=:id");
        query->bindValue(":id", id);
        query->bindValue(":title", QString::fromStdString(model->GetTitle()));
        query->exec();
    }

    QuestionRepository::QuestionRepository(): Repository<models::Question>() {
        this->Init();
    }

    string QuestionRepository::GetTableName() {
        return "Questions";
    }

    SqlQueryParser<models::Question>* QuestionRepository::GetSqlQueryParser() {
        return new QuestionSqlParser();
    }

    void QuestionRepository::Create(models::Question* model) {
        QSqlQuery* query = new QSqlQuery();
        query->prepare("INSERT INTO \"" + QString::fromStdString(this->tableName) + "\" (id, title, type_id, quiz_id, score) VALUES (:id, :title, :type_id, :quiz_id, :score)");
        query->bindValue(":id", model->GetId());
        query->bindValue(":title", model->GetTitle().c_str());
        query->bindValue(":type_id", model->GetTypeId());
        query->bindValue(":quiz_id", model->GetQuizId());
        query->bindValue(":score", model->GetScore());
        query->exec();
    }

    void QuestionRepository::Update(int id, models::Question* model) {
        QSqlQuery* query = new QSqlQuery();
        query->prepare("UPDATE \"" + QString::fromStdString(this->tableName) + "\" SET title=:title, type_id=:type_id, quiz_id=:quiz_id, score=:score WHERE id=:id");
        query->bindValue(":id", model->GetId());
        query->bindValue(":title", model->GetTitle().c_str());
        query->bindValue(":type_id", model->GetTypeId());
        query->bindValue(":quiz_id", model->GetQuizId());
        query->bindValue(":score", model->GetScore());
        query->exec();
    }

    QuizRepository::QuizRepository(): Repository<models::Quiz>() {
        this->Init();
    }

    string QuizRepository::GetTableName() {
        return "Quizzes";
    }

    SqlQueryParser<models::Quiz>* QuizRepository::GetSqlQueryParser() {
        return new QuizSqlParser();
    }

    void QuizRepository::Create(models::Quiz *model) {
        QSqlQuery* query = new QSqlQuery();
        query->prepare("INSERT INTO \"" + QString::fromStdString(this->tableName) + "\" (id, title) VALUES (:id, :title)");
        query->bindValue(":id", model->GetId());
        query->bindValue(":title", QString::fromStdString(model->GetTitle()));
        query->exec();
    }

    void QuizRepository::Update(int id, models::Quiz* model) {
        QSqlQuery* query = new QSqlQuery();
        query->prepare("UPDATE \"" + QString::fromStdString(this->tableName) + "\" SET title=:title WHERE id=:id");
        query->bindValue(":id", id);
        query->bindValue(":title", QString::fromStdString(model->GetTitle()));
        query->exec();
    }

    VariantRepository::VariantRepository(): Repository<models::Variant>() {
        this->Init();
    }

    string VariantRepository::GetTableName() {
        return "Variants";
    }

    SqlQueryParser<models::Variant>* VariantRepository::GetSqlQueryParser() {
        return new VariantSqlParser();
    }

    void VariantRepository::Create(models::Variant *model) {
        QSqlQuery* query = new QSqlQuery();
        query->prepare("INSERT INTO \"" + QString::fromStdString(this->tableName) + "\" (id, question_id, variant, is_answer) VALUES (:id, :question_id, :variant, :is_answer)");
        query->bindValue(":id", model->GetId());
        query->bindValue(":question_id", model->GetQuestionId());
        query->bindValue(":variant", QString::fromStdString(model->GetVariant()));
        query->bindValue(":is_answer", model->GetIsAnswer());
        query->exec();
    }

    void VariantRepository::Update(int id, models::Variant* model) {
        QSqlQuery* query = new QSqlQuery();
        query->prepare("UPDATE \"" + QString::fromStdString(this->tableName) + "\" SET question_id=:question_id, variant=:variant, is_answer=:is_answer WHERE id=:id");
        query->bindValue(":id", model->GetId());
        query->bindValue(":question_id", model->GetQuestionId());
        query->bindValue(":variant", QString::fromStdString(model->GetVariant()));
        query->bindValue(":is_answer", model->GetIsAnswer());
        query->exec();
    }

}
