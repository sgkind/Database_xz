#include "schedulequerywidget.h"
#include "ui_schedulequerywidget.h"
#include <QDebug>

ScheduleQueryWidget::ScheduleQueryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScheduleQueryWidget)
{
    ui->setupUi(this);
}

ScheduleQueryWidget::~ScheduleQueryWidget()
{
    delete ui;
}

void ScheduleQueryWidget::on_qeBtn_clicked()
{
    int idx1 = -1;
    int idx2 = -1;
    QString str1 = ui->qcEngineerLineEdit->text().trimmed();
    QString str2 = ui->qeEngineerLineEdit->text().trimmed();

    if (!str1.isEmpty())
        idx1 = 0;
    if (!str2.isEmpty())
        idx2 = 1;

    emit BtnClicked(idx1, str1, idx2 ,str2, true);
}

void ScheduleQueryWidget::on_qcBtn_clicked()
{
    int idx1 = -1;
    int idx2 = -1;

    QString str1 = ui->qxCodeLineEdit->text().trimmed();
    QString str2 = ui->qcCodeLineEdit->text().trimmed();

    if (!str1.isEmpty())
        idx1 = 2;
    if (!str2.isEmpty())
        idx2 = 3;

    emit BtnClicked(idx1, str1, idx2, str2, true);

}

void ScheduleQueryWidget::on_deBtn_clicked()
{
    int idx1 = -1;
    int idx2 = -1;
    QString str1 = ui->dcEngineerLineEdit->text().trimmed();
    QString str2 = ui->deEngineerLineEdit->text().trimmed();

    if (!str1.isEmpty())
        idx1 = 0;
    if (!str2.isEmpty())
        idx2 = 1;

    emit BtnClicked(idx1, str1, idx2 ,str2, false);
}

void ScheduleQueryWidget::on_dcBtn_clicked()
{
    int idx1 = -1;
    int idx2 = -1;

    QString str1 = ui->dxCodeLineEdit->text().trimmed();
    QString str2 = ui->dcCodeLineEdit->text().trimmed();

    if (!str1.isEmpty())
        idx1 = 2;
    if (!str2.isEmpty())
        idx2 = 3;

    emit BtnClicked(idx1, str1, idx2, str2, false);
}
