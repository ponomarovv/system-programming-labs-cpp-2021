QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DataSource.cpp \
    FileDataSource.cpp \
    GroupBox.cpp \
    GroupBoxFactory.cpp \
    Models.cpp \
    MultipleGroupBox.cpp \
    OnlyOneGroupBox.cpp \
    Question.cpp \
    QuestionFactory.cpp \
    Quiz.cpp \
    Repositories.cpp \
    Services.cpp \
    Specifications.cpp \
    SqlQueryParser.cpp \
    TextAnswerGroupBox.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    DataSource.h \
    Factories.h \
    GroupBox.h \
    Models.h \
    Question.h \
    Quiz.h \
    Repositories.h \
    Services.h \
    Specifications.h \
    SqlQueryParsers.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
