#ifndef FILEDATASOURCE_H
#define FILEDATASOURCE_H

#include "Question.h"
#include "DataSource.h"

namespace quiz {

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
