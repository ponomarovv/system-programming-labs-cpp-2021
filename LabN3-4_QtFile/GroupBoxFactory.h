#ifndef GROUPBOXFACTORY_H
#define GROUPBOXFACTORY_H

#include "GroupBox.h"

namespace quiz {
    class GroupBoxFactory {

        public:
            static GroupBox* GetByQuestion(QWidget* widget, Question* question);

        private:
            GroupBoxFactory();

    };
}

#endif // GROUPBOXFACTORY_H
