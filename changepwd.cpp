#include "changepwd.h"

ChangePwd::ChangePwd(QWidget *parent) : QDialog(parent)
{
    passwordLabel = new QLabel(tr("原有密码："));
    passwordLineEdit = new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    newPasswordLabel = new QLabel(tr("请输入新密码："));
    newPasswordLineEdit = new QLineEdit;
    newPasswordLineEdit->setEchoMode(QLineEdit::Password);
    newPasswordLabel_c = new QLabel(tr("请确认新密码："));
    newPasswordLineEdit_c = new QLineEdit;
    newPasswordLineEdit_c->setEchoMode(QLineEdit::Password);
    message = new QLabel(tr(""));

    topLayout = new QGridLayout();

    topLayout->addWidget(passwordLabel, 0, 0);
    topLayout->addWidget(passwordLineEdit, 0, 1);
    topLayout->addWidget(newPasswordLabel, 1, 0);
    topLayout->addWidget(newPasswordLineEdit, 1, 1);
    topLayout->addWidget(newPasswordLabel_c, 2, 0);
    topLayout->addWidget(newPasswordLineEdit_c, 2, 1);
    topLayout->addWidget(message, 3, 0, 1, 2);

    okBtn = new QPushButton(tr("确定"));
    cancelBtn = new QPushButton(tr("取消"));

    bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(cancelBtn);
    bottomLayout->addSpacing(6);
    bottomLayout->addWidget(okBtn);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(bottomLayout);
}

ChangePwd::~ChangePwd()
{

}
