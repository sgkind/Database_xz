#include "login.h"

Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setFixedSize(400, 300);
    setWindowTitle(tr("欢迎登录"));
    ui->userNameLineEdit->setFocus();
    ui->loginBtn->setDefault(true);

}

Login::~Login()
{
    delete ui;
}

void Login::on_loginBtn_clicked()
{
    if(ui->userNameLineEdit->text().trimmed().isEmpty())
    {
        QMessageBox::information(this, tr(""), tr(""), QMessageBox::Ok);
        ui->userNameLineEdit->setFocus();
    }
    if(ui->passwordLineEdit->text().trimmed().isEmpty())
    {
        QMessageBox::information(this, tr("请输入密码"), tr("请先输入密码再登录!"), QMessageBox::Ok);
    } else {
         QString username = ui->userNameLineEdit->text().trimmed();
         QString password = ui->passwordLineEdit->text().trimmed();
         QSqlQuery query;
         bool success = query.exec(QString("select * from users where name = '%1'").arg(username));
         if (success && query.next()) {
             QString user_password = query.value(2).toString();
             int authority = query.value(3).toInt();

             if (password == user_password)
                 QDialog::accept();
             else {
                 QMessageBox::warning(this, tr("密码错误"), tr("请先输入正确的密码再登录"), QMessageBox::Ok);
                 ui->passwordLineEdit->clear();
             }
         } else {
             QMessageBox::warning(this, tr("密码错误"), tr("请先输入正确的密码再登录"), QMessageBox::Ok);
             ui->passwordLineEdit->clear();
         }
    }

}

void Login::on_quitBtn_clicked()
{
    QDialog::reject();
}
