#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "ui_logindialog.h"



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

private:
    Ui::LoginDialog *ui;


};

#endif //    QDialog::reject(); LOGIN_H
