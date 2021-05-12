#include "FileDataSource.h"
#include "DataSource.h"
#include "QuestionFactory.h"

#include "string.h"

namespace quiz {

    FileDataSource::FileDataSource(const char* filepath): DataSource() {
        this->filepath = filepath;
    }

    FileDataSource::~FileDataSource() {
        if (source != NULL) {
            fclose(source);
        }
    }

    int FileDataSource::GetQuestionsCount() {
        source = fopen(this->filepath, "r");
        reading = true;
        int amount;
        fscanf(source, "%d\n", &amount);
        return amount;
    }

    Question* FileDataSource::GetNextQuestion() {
        if (!reading) {
            return NULL;
        }
        char type[256], text[256];
        fscanf(source, "%[^\n]s", type);
        fscanf(source, "\n");
        fscanf(source, "%[^\n]s", text);
        fscanf(source, "\n");
        if (strcmp(type, "multiple") == 0) {
            return GetMultipleQuestion(text);
        } else if (strcmp(type, "non-multiple") == 0) {
            return GetOneCorrentQuestion(text);
        } else if (strcmp(type, "text-field") == 0) {
            return GetTextQuestion(text);
        }
        return NULL;
    }

    Question* FileDataSource::GetMultipleQuestion(string text) {
        int optionsCount, answersCount, score;
        vector<string> options, answers;
        fscanf(source, "%d\n", &optionsCount);
        options = ReadArray(optionsCount);
        fscanf(source, "%d\n", &answersCount);
        answers = ReadArray(answersCount);
        fscanf(source, "%d\n", &score);
        return QuestionFactory::CreateMultipleQuestion(
                    text, options, answers, score
        );
    }

    Question* FileDataSource::GetOneCorrentQuestion(string text) {
        int optionsCount, score;
        vector<string> options;
        char answer[256];
        fscanf(source, "%d\n", &optionsCount);
        options = ReadArray(optionsCount);
        fscanf(source, "%[^\n]s", answer);
        fscanf(source, "\n");
        fscanf(source, "%d\n", &score);
        return QuestionFactory::CreateOneCorrectQuestion(
                    text, options, answer, score
        );
    }

    Question* FileDataSource::GetTextQuestion(string text) {
        int score;
        char answer[256];
        fscanf(source, "%[^\n]s", answer);
        fscanf(source, "\n");
        fscanf(source, "%d\n", &score);
        return QuestionFactory::CreateTextQuestion(
                    text, answer, score
        );
    }

    vector<string> FileDataSource::ReadArray(int count) {
        vector<string> answer;
        for (int i = 0; i < count; i++) {
            char value[256];
            fscanf(source, "%[^\n]s", value);
            fscanf(source, "\n");
            answer.push_back(value);
        }
        return answer;
    }

    void FileDataSource::Finish() {
        fclose(source);
        reading = false;
    }

}
