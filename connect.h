#ifndef CONNECT_H
#define CONNECT_H

#include <QSqlDatabase>
#include <QDebug>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");

    db.setDatabaseName("fuck");
    //db.setUserName("sgkind");
    db.setUserName("root");
    db.setPassword("526157sgk");
    bool success = db.open();

    if (success) {
        qDebug() << "Open database success!";
        return true;
    } else
    {
        qDebug() << "Open database failed...";
        return false;
    }

}

#endif // CONNECT_H
