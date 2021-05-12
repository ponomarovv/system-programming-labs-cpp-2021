#ifndef MODELS_H
#define MODELS_H

#include <string>

using namespace std;

namespace models {

    class Type {
        public:
            Type();
            ~Type();
            int GetId();
            void SetId(int id);
            string GetTitle();
            void SetTitle(string title);

        private:
            int id;
            string title;
    };

    class Quiz {
        public:
            Quiz();
            ~Quiz();
            int GetId();
            void SetId(int id);
            string GetTitle();
            void SetTitle(string title);

        private:
            int id;
            string title;
    };

    class Question {
        public:
            Question();
            ~Question();
            int GetId();
            void SetId(int id);
            string GetTitle();
            void SetTitle(string title);
            int GetTypeId();
            void SetTypeId(int typeId);
            int GetQuizId();
            void SetQuizId(int quizId);
            int GetScore();
            void SetScore(int score);

        private:
            int id;
            string title;
            int typeId;
            int quizId;
            int score;
    };

    class Variant {
        public:
            Variant();
            ~Variant();
            int GetId();
            void SetId(int id);
            int GetQuestionId();
            void SetQuestionId(int questionId);
            string GetVariant();
            void SetVariant(string variant);
            bool GetIsAnswer();
            void SetIsAnswer(bool isAnswer);

        private:
            int id;
            int questionId;
            string variant;
            bool isAnswer;
    };

}

#endif // MODELS_H
