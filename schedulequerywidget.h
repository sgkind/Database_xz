#ifndef SCHEDULEQUERYWIDGET_H
#define SCHEDULEQUERYWIDGET_H

#include <QWidget>

namespace Ui {
class ScheduleQueryWidget;
}

class ScheduleQueryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleQueryWidget(QWidget *parent = 0);
    ~ScheduleQueryWidget();

private:
    Ui::ScheduleQueryWidget *ui;

signals:
    void BtnClicked(int idx1, QString str1, int idx2, QString str2, bool flags);
private slots:
    void on_qeBtn_clicked();
    void on_qcBtn_clicked();
    void on_deBtn_clicked();
    void on_dcBtn_clicked();
};

#endif // SCHEDULEQUERYWIDGET_H
