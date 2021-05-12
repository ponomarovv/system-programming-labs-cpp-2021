#include "GroupBox.h"
#include "Factories.h"
#include "Question.h"

#include <QWidget>

namespace quiz {
    GroupBoxFactory::GroupBoxFactory() {}

    GroupBox* GroupBoxFactory::GetByQuestion(QWidget* widget, Question* question) {
        if (question->GetType() == "multiple") {
            return new MultipleGroupBox(widget, question);
        }
        if (question->GetType() == "non-multiple") {
            return new OnlyOneGroupBox(widget, question);
        }
        if (question->GetType() == "text-field") {
            return new TextAnswerGroupBox(widget, question);
        }
        return NULL;
    }
}
