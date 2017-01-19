#ifndef USER_H
#define USER_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>

class User
{
public:
    static User* getInstance();
    bool login(QString uname, QString upassword);
    QString getName();
    int getAuthority();

private:
    User();
    User(const User&);
    User& operator=(const User&) = delete;

    static User* instance;
    QString name;
    QString password;
    int authority;
    bool isLogin;
};

#endif // USER_H
