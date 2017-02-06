#ifndef SCHEDULEQUERYTABLEVIEW_H
#define SCHEDULEQUERYTABLEVIEW_H

#include <QTableView>
#include <QSqlTableModel>
#include "mydelegate.h"
#include "mymodel.h"
#include "mydelegate.h"

class ScheduleQueryTableView : public QTableView
{
    Q_OBJECT

public:
    ScheduleQueryTableView();
    ~ScheduleQueryTableView();

    void scheduleFilter(int idx1, QString str1, int idx2, QString str2, bool flags);

private:
    ScheduleModel *scheduleQueryModel;
    QStringList strList;
    CheckBoxDelegateNoEditor *checkBoxDelegateNoEditor;
};

#endif // SCHEDULEQUERYTABLEVIEW_H
