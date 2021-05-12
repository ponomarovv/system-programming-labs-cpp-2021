#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
    public:
        Question();
        Question(std::string text, std::vector<std::string> variants);
        ~Question();

        std::string getText();
        void setText(std::string text);

        std::vector<std::string> getVariants();
        void setVariants(std::vector<std::string> variants);

    private:
        std::string text;
        std::vector<std::string> variants;
};

#endif // QUESTION_H
