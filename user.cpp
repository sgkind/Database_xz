#include "user.h"
#include <QDebug>
#include <QSqlQuery>

User::User()
{

}

User::User(const User&) {

}

User* User::instance = new User();

User* User::getInstance() {
    return instance;
}

bool User::login(QString uname, QString upassword) {
    QSqlQuery query;
    bool success = query.exec(QString("select * from users where name='%1'").arg(uname));
    if (success && query.next()) {
        name = uname;
        password = query.value(2).toString();
        qDebug() << password << "password";
        authority = query.value(3).toInt();
        qDebug() << authority << "authority";
    } else
        return false;

    if (password == upassword) {
        isLogin = true;
    } else {
        authority = -1;
        return false;
    }

    return true;
}

QString User::getName() {
    if (isLogin)
        return name;
    else
        return QString("");
}

int User::getAuthority() {
    return authority;
}
