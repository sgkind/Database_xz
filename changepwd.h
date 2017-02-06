#ifndef CHANGEPWD_H
#define CHANGEPWD_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ChangePwd : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePwd(QWidget *parent = 0);
    ~ChangePwd();

private:
    QLabel     *passwordLabel;
    QLineEdit  *passwordLineEdit;
    QLabel     *newPasswordLabel;
    QLineEdit  *newPasswordLineEdit;
    QLabel     *newPasswordLabel_c;
    QLineEdit  *newPasswordLineEdit_c;
    QLabel     *message;

    QPushButton *okBtn;
    QPushButton *cancelBtn;

    QGridLayout *topLayout;
    QHBoxLayout *bottomLayout;
    QVBoxLayout *mainLayout;
};

#endif // CHANGEPWD_H
