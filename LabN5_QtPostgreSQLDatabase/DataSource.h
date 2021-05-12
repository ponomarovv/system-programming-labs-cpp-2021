#ifndef DATASOURCE_H
#define DATASOURCE_H

#include "Question.h"

namespace quiz {

    class DataSource {
        public:
            DataSource();
            ~DataSource();
            virtual int GetQuestionsCount() = 0;
            virtual Question* GetNextQuestion() = 0;
            virtual void Finish() = 0;

        protected:
            int questionsCount;
            vector<Question*> questions;
            bool reading;
    };

    class FileDataSource: public DataSource {
        public:
            FileDataSource(const char* filename);
            ~FileDataSource();
            int GetQuestionsCount();
            Question* GetNextQuestion();
            void Finish();

        private:
            FILE* source;
            const char* filepath;
            Question* GetMultipleQuestion(string text);
            Question* GetOneCorrentQuestion(string text);
            Question* GetTextQuestion(string text);
            vector<string> ReadArray(int count);
    };

}

#endif // DATASOURCE_H
