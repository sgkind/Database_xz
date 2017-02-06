#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QTabWidget>

#include <QWidget>
#include <QTreeWidget>
#include <QStackedWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QTableView>
#include <QSqlTableModel>
#include <QMenu>
#include <QLabel>


#include "user.h"
#include "mymodel.h"
#include "customwidget.h"
#include "schedulequerywidget.h"
#include "schedulequerytableview.h"
#include "newtasktableview.h"
#include "scheduletableview.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);

private:
    QTreeWidget *treeWidget;
    CustomWidget *arrowWidget;
    QStackedWidget *stackWidget;

    ScheduleQueryWidget *scheduleQueryWidget;


    QTableView *contactTableView;
    QTableView *projectInfoTableView;
    QTableView *customerTableView;
    QTableView *weekplanFinishedTableView;
    QTableView *weekplanUnfinishedTableView;
    ScheduleTableView *scheduleTableView;
    ScheduleTableView *scheduleUpdateTableView;
    ScheduleQueryTableView *scheduleQueryTableView;
    NewTaskTableView *newTaskTableView;

    QTreeWidgetItem *contactItem;
    QTreeWidgetItem *projectInfoItem;
    QTreeWidgetItem *customerItem;
    QTreeWidgetItem *weekplanItem;
    QTreeWidgetItem *weekplanItem1;
    QTreeWidgetItem *weekplanItem2;
    QTreeWidgetItem *scheduleItem;
    QTreeWidgetItem *scheduleUpdateItem;
    QTreeWidgetItem *newTaskItem;
    QTreeWidgetItem *scheduleQueryItem;
    QTreeWidgetItem *basicInformationItem;
    QTreeWidgetItem *blowInformation;
    QTreeWidgetItem *ptcInformation;
    QTreeWidgetItem *harnessInformation_1;
    QTreeWidgetItem *harnessInformation_2;
    QTreeWidgetItem *wireInformation;
    QTreeWidgetItem *housingInformation;
    QTreeWidgetItem *termainalInformation;
    QTreeWidgetItem *relayInformation;

    QHBoxLayout *mainLayout;

    void contacts();
    MyModel *contactsModel;

    void projectInfos();
    MyModel *projectInfoModel;

    void customers();
    MyModel *customersModel;

    void weekplansFinished();
    WeekplanModel *weekplansFinishedModel;

    void weekplansUnfinished();
    WeekplanModel *weekplansUnfinishedModel;

    //void scheduleUpdate();
    //ScheduleModel *scheduleUpdateModel;



    QMenu *menu;

    User *user;

signals:

public slots:
    void addContact(QModelIndex);
    void slotAdd();
    void slotDelete();

    void customContextMenu(QPoint);

    void changeStack(QTreeWidgetItem* item, int);

    void arrowWidget_slot();

    void query_slot(int idx1, QString str1, int idx2, QString str2, bool flags);
};

#endif // MAINWIDGET_H
