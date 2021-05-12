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

}

#endif // DATASOURCE_H
