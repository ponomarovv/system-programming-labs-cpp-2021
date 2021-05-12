#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "Models.h"
#include "Repositories.h"
#include "Specifications.h"
#include "SqlQueryParsers.h"
#include "Services.h"

bool OpenDb();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool result = OpenDb();

    if (!result) {
        QMessageBox* box = new QMessageBox();
        box->setWindowTitle("Помилка");
        box->setText("На жаль, не вдалося підключитись до бази даних. Спробуйте запустити прогрум пізніше");
        box->exec();
        return 0;
    }

    MainWindow w;
    w.show();
    return a.exec();
}

bool OpenDb() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("Quiz");
    db.setUserName("postgres");
    db.setPassword("postgres");

    return db.open();
}
