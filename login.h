#ifndef LOGIN_H
#define LOGIN_H

#include "ui_logindialog.h"
#include "user.h"

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QTimer>

namespace Ui {
class LoginDialog;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_loginBtn_clicked();

    void on_quitBtn_clicked();

    void on_userNameLineEdit_textEdited(const QString &arg1);

    void on_passwordLineEdit_textEdited(const QString &arg1);

private:
    Ui::LoginDialog *ui;
    User* user;
    QSettings *config;
    QTimer *autoTimer;

    QString username;
    QString password;
    bool rememberPwd;
    bool autoLogin;
};

#endif //    QDialog::reject(); LOGIN_H
