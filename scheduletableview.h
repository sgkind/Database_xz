#ifndef SCHEDULETABLEVIEW_H
#define SCHEDULETABLEVIEW_H

#include "mymodel.h"
#include "mydelegate.h"
#include "user.h"

#include <QTableView>



class ScheduleTableView : public QTableView
{
    Q_OBJECT

public:
    ScheduleTableView(bool _update);
    ~ScheduleTableView();

    void updateData();

private:
    bool update;
    ScheduleModel *scheduleModel;
    QStringList headerStr;

    User *user;
};

#endif // SCHEDULETABLEVIEW_H
