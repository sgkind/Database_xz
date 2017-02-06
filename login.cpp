#include "login.h"
#include <QImage>
#include <QPixmap>

Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //setFixedSize(400, 300);
    setWindowTitle(tr("欢迎登录"));


    autoTimer = new QTimer(this);
    connect(autoTimer, SIGNAL(timeout()), this, SLOT(on_loginBtn_clicked()));

    ui->userNameLineEdit->setFocus();
    ui->loginBtn->setDefault(true);

    config = new QSettings(QString("config.ini"), QSettings::IniFormat);
    config->beginGroup("User");
    rememberPwd = config->value("记住密码").toBool();
    autoLogin = config->value("自动登录").toBool();
    username = config->value("用户名").toString();
    password = config->value("密码").toString();
    config->endGroup();

    if (rememberPwd) {
        ui->userNameLineEdit->setText(username);
        ui->passwordLineEdit->setText(password);
        ui->rememberPwdCheckBox->setChecked(true);
    }

    if (autoLogin) {
        ui->AutoLoginCheckBox->setChecked(true);
        autoTimer->start(3000);
    }

}

Login::~Login()
{
    delete ui;
}

void Login::on_loginBtn_clicked()
{
    autoTimer->stop();
    if(ui->userNameLineEdit->text().trimmed().isEmpty())
    {
        QMessageBox::information(this, tr("请输入用户名"), tr("请先输入用户名"), QMessageBox::Ok);
        ui->userNameLineEdit->setFocus();
    }
    else if(ui->passwordLineEdit->text().trimmed().isEmpty())
    {
        QMessageBox::information(this, tr("请输入密码"), tr("请先输入密码再登录!"), QMessageBox::Ok);
    } else {
         username = ui->userNameLineEdit->text().trimmed();
         password = ui->passwordLineEdit->text().trimmed();
         user = User::getInstance();
         if (user->login(username, password)){
             if(ui->rememberPwdCheckBox->isChecked()) {
                 config->beginGroup("User");
                 config->setValue("记住密码", true);
                 config->setValue("自动登录", ui->AutoLoginCheckBox->isChecked());
                 config->setValue("用户名", username);
                 config->setValue("密码", password);
                 config->endGroup();
             } else if (!ui->rememberPwdCheckBox->isChecked()) {
                 config->beginGroup("User");
                 config->setValue("记住密码", false);
                 config->setValue("自动登录", false);
                 config->setValue("用户名", "");
                 config->setValue("密码", "");
                 config->endGroup();
             }
             QDialog::accept();
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

void Login::on_userNameLineEdit_textEdited(const QString &arg1)
{
    autoTimer->stop();
}

void Login::on_passwordLineEdit_textEdited(const QString &arg1)
{
    autoTimer->stop();
}
