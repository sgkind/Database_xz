#ifndef NEWTASKTABLEVIEW_H
#define NEWTASKTABLEVIEW_H

#include <QTableView>
#include <QStringList>
#include "mymodel.h"
#include "mydelegate.h"


class NewTaskTableView : public QTableView
{
    Q_OBJECT

public:
    NewTaskTableView();
    ~NewTaskTableView();

    void updateData();

private:
    ScheduleModel *newTaskModel;
    CalendarDelegate *calendarDelegate;
    QStringList headerStr;

};

#endif // NEWTASKTABLEVIEW_H
