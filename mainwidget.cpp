#include "mainwidget.h"
#include "mydelegate.h"
#include <QDebug>
#include <QMessageBox>
#include <QFont>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    user = User::getInstance();
    treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderLabel("导航菜单");
    treeWidget->setStyleSheet("background-color: #5B6771; font-size:14px; color:white");

    arrowWidget = new CustomWidget();
    connect(arrowWidget, SIGNAL(doubleClicked()), this, SLOT(arrowWidget_slot()));

    stackWidget = new QStackedWidget();

    scheduleQueryWidget = new ScheduleQueryWidget;
    connect(scheduleQueryWidget, SIGNAL(BtnClicked(int,QString,int ,QString, bool)), this, SLOT(query_slot(int,QString,int,QString, bool)));

    contacts();
    projectInfos();
    customers();
    weekplansFinished();
    weekplansUnfinished();

    scheduleTableView = new ScheduleTableView(false);
    scheduleUpdateTableView = new ScheduleTableView(true);

    scheduleQueryTableView = new ScheduleQueryTableView;
    newTaskTableView = new NewTaskTableView;
    //增加右键菜单
    newTaskTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(newTaskTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenu(QPoint)));



    stackWidget->addWidget(contactTableView);
    stackWidget->addWidget(projectInfoTableView);
    stackWidget->addWidget(customerTableView);
    stackWidget->addWidget(weekplanUnfinishedTableView);
    stackWidget->addWidget(weekplanFinishedTableView);
    stackWidget->addWidget(scheduleTableView);
    stackWidget->addWidget(scheduleUpdateTableView);
    stackWidget->addWidget(newTaskTableView);
    stackWidget->addWidget(scheduleQueryWidget);
    stackWidget->addWidget(scheduleQueryTableView);



    contactItem = new QTreeWidgetItem(QStringList("供应商联系信息查询及录入"));
    projectInfoItem = new QTreeWidgetItem(QStringList("项目信息录入"));
    customerItem = new QTreeWidgetItem(QStringList("新客户增加"));
    weekplanItem = new QTreeWidgetItem(QStringList("电器组周计划录入&查询"));
    scheduleItem = new QTreeWidgetItem(QStringList("产品进度查询"));
    scheduleUpdateItem = new QTreeWidgetItem(QStringList("产品开发进度更新"));
    newTaskItem = new QTreeWidgetItem(QStringList("开发任务下发及进度汇总"));
    scheduleQueryItem = new QTreeWidgetItem(QStringList("项目开发进度及延期查询"));
    basicInformationItem = new QTreeWidgetItem(QStringList("技术基础信息输入&查询"));




    treeWidget->addTopLevelItem(contactItem);
    treeWidget->addTopLevelItem(projectInfoItem);
    treeWidget->addTopLevelItem(customerItem);
    treeWidget->addTopLevelItem(weekplanItem);
    treeWidget->addTopLevelItem(scheduleItem);
    treeWidget->addTopLevelItem(scheduleUpdateItem);
    treeWidget->addTopLevelItem(newTaskItem);
    treeWidget->addTopLevelItem(scheduleQueryItem);
    treeWidget->addTopLevelItem(basicInformationItem);

    weekplanItem1 = new QTreeWidgetItem(QStringList("周计划录入及查询"));
    weekplanItem2 = new QTreeWidgetItem(QStringList("已完成周计划查询"));
    weekplanItem->addChild(weekplanItem1);
    weekplanItem->addChild(weekplanItem2);

    blowInformation = new QTreeWidgetItem(QStringList("01-风机&电子风扇数据录入"));
    ptcInformation = new QTreeWidgetItem(QStringList("02-PTC数据汇总数据库"));
    harnessInformation_1 = new QTreeWidgetItem(QStringList("03-线束零部件件号查询"));
    harnessInformation_2 = new QTreeWidgetItem(QStringList("04-线束零部件查询总表"));
    wireInformation = new QTreeWidgetItem(QStringList("05-导线信息查询及录入"));
    housingInformation = new QTreeWidgetItem(QStringList("06-护套信息查询及录入"));
    termainalInformation = new QTreeWidgetItem(QStringList("07-端子信息查询及录入"));
    relayInformation = new QTreeWidgetItem(QStringList("08-继电器信息查询及录入"));

    basicInformationItem->addChild(blowInformation);
    basicInformationItem->addChild(ptcInformation);
    basicInformationItem->addChild(harnessInformation_1);
    basicInformationItem->addChild(harnessInformation_2);
    basicInformationItem->addChild(wireInformation);
    basicInformationItem->addChild(housingInformation);
    basicInformationItem->addChild(termainalInformation);
    basicInformationItem->addChild(relayInformation);


    treeWidget->show();

    treeWidget->setFixedWidth(230);

    connect(treeWidget, SIGNAL(itemActivated(QTreeWidgetItem*,int)), this, SLOT(changeStack(QTreeWidgetItem*,int)));

    mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(1);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(treeWidget);
    mainLayout->addWidget(arrowWidget);
    mainLayout->addWidget(stackWidget);
    arrowWidget->hide();
    setLayout(mainLayout);
}

void MainWidget::contacts()
{
    contactTableView = new QTableView;
    contactTableView->updatesEnabled();

    QFont font;
    font.setPointSize(fontSize);
    contactTableView->setFont(font);

    contactsModel = new MyModel(this);
    contactsModel->setTable(QString("contacts"));
    contactsModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    contactsModel->select();

    contactsModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    contactsModel->setHeaderData(1, Qt::Horizontal, QObject::tr("公司名称"));
    contactsModel->setHeaderData(2, Qt::Horizontal, QObject::tr("技术人员姓名"));
    contactsModel->setHeaderData(3, Qt::Horizontal, QObject::tr("职位"));
    contactsModel->setHeaderData(4, Qt::Horizontal, QObject::tr("联系电话"));
    contactsModel->setHeaderData(5, Qt::Horizontal, QObject::tr("邮箱"));

    //增加右键菜单
    contactTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(contactTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenu(QPoint)));

    //绑定数据
    contactTableView->setModel(contactsModel);

    //隐藏id列
    contactTableView->setColumnHidden(0, true );

    contactTableView->setColumnWidth(1, 200);
    contactTableView->setColumnWidth(2, 100);
    contactTableView->setColumnWidth(3, 120);
    contactTableView->setColumnWidth(4, 120);
    contactTableView->setColumnWidth(5, 250);

}

void MainWidget::projectInfos()
{
    projectInfoTableView = new QTableView;
    projectInfoTableView->updatesEnabled();
    QFont font;
    font.setPointSize(fontSize);
    projectInfoTableView->setFont(font);

    projectInfoModel = new MyModel(this);
    projectInfoModel->setTable(QString("projectinfo"));
    projectInfoModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    projectInfoModel->select();

    projectInfoModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    projectInfoModel->setHeaderData(1, Qt::Horizontal, QObject::tr("项目名称"));
    projectInfoModel->setHeaderData(2, Qt::Horizontal, QObject::tr("客户名称"));

    //增加右键菜单
    projectInfoTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(projectInfoTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenu(QPoint)));

    //绑定数据
    projectInfoTableView->setModel(projectInfoModel);
    projectInfoTableView->setColumnHidden(0, true);
}

void MainWidget::customers()
{
    customerTableView = new QTableView;
    customerTableView->updatesEnabled();
    QFont font;
    font.setPointSize(fontSize);
    customerTableView->setFont(font);

    //customersModel = new QSqlTableModel(this);
    customersModel = new MyModel(this);
    customersModel->setTable(QString("customers"));
    customersModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    customersModel->select();

    customersModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    customersModel->setHeaderData(1, Qt::Horizontal, QObject::tr("客户名称"));
    customersModel->setHeaderData(2, Qt::Horizontal, QObject::tr("驻点联系人"));
    customersModel->setHeaderData(3, Qt::Horizontal, QObject::tr("驻点电话"));
    customersModel->setHeaderData(4, Qt::Horizontal, QObject::tr("驻点邮箱"));

    //增加右键菜单
    customerTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(customerTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenu(QPoint)));

    //绑定数据
    customerTableView->setModel(customersModel);
    customerTableView->setColumnHidden(0, true);

    //设置列宽
    customerTableView->setColumnWidth(1, 100);
    customerTableView->setColumnWidth(2, 100);
    customerTableView->setColumnWidth(3, 120);
    customerTableView->setColumnWidth(4, 250);
}

void MainWidget::weekplansFinished()
{
    weekplanFinishedTableView = new QTableView;
    weekplanFinishedTableView->setEditTriggers(QTableView::NoEditTriggers);
    QFont font;
    font.setPointSize(fontSize);
    weekplanFinishedTableView->setFont(font);

    weekplansFinishedModel = new WeekplanModel(this);
    weekplansFinishedModel->setTable(QString("weekplans"));
    weekplansFinishedModel->select();

    weekplansFinishedModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    weekplansFinishedModel->setHeaderData(1, Qt::Horizontal, QObject::tr("姓名"));
    weekplansFinishedModel->setHeaderData(2, Qt::Horizontal, QObject::tr("起始日期"));
    weekplansFinishedModel->setHeaderData(3, Qt::Horizontal, QObject::tr("截止日期"));
    weekplansFinishedModel->setHeaderData(4, Qt::Horizontal, QObject::tr("产品名称"));
    weekplansFinishedModel->setHeaderData(5, Qt::Horizontal, QObject::tr("周计划内容"));
    weekplansFinishedModel->setHeaderData(6, Qt::Horizontal, QObject::tr("所属项目"));
    weekplansFinishedModel->setHeaderData(7, Qt::Horizontal, QObject::tr("是否出图"));
    weekplansFinishedModel->setHeaderData(8, Qt::Horizontal, QObject::tr("是否出技术协议"));
    weekplansFinishedModel->setHeaderData(9, Qt::Horizontal, QObject::tr("是否完成"));
    weekplansFinishedModel->setHeaderData(10, Qt::Horizontal, QObject::tr("所用工时"));
    weekplansFinishedModel->setHeaderData(11, Qt::Horizontal, QObject::tr("完成日期"));
    weekplansFinishedModel->setHeaderData(12, Qt::Horizontal, QObject::tr("延期原因"));
    weekplansFinishedModel->setHeaderData(13, Qt::Horizontal, QObject::tr("备注"));

}

void MainWidget::weekplansUnfinished()
{
    weekplanUnfinishedTableView = new QTableView;
    weekplanUnfinishedTableView->updatesEnabled();
    QFont font;
    font.setPointSize(fontSize);
    weekplanUnfinishedTableView->setFont(font);

    weekplansUnfinishedModel = new WeekplanModel(this);
    weekplansUnfinishedModel->setTable(QString("weekplans"));
    weekplansUnfinishedModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    weekplansUnfinishedModel->select();

    weekplansUnfinishedModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    weekplansUnfinishedModel->setHeaderData(1, Qt::Horizontal, QObject::tr("姓名"));
    weekplansUnfinishedModel->setHeaderData(2, Qt::Horizontal, QObject::tr("起始日期"));
    weekplansUnfinishedModel->setHeaderData(3, Qt::Horizontal, QObject::tr("截止日期"));
    weekplansUnfinishedModel->setHeaderData(4, Qt::Horizontal, QObject::tr("产品名称"));
    weekplansUnfinishedModel->setHeaderData(5, Qt::Horizontal, QObject::tr("周计划内容"));
    weekplansUnfinishedModel->setHeaderData(6, Qt::Horizontal, QObject::tr("所属项目"));
    weekplansUnfinishedModel->setHeaderData(7, Qt::Horizontal, QObject::tr("是否出图"));
    weekplansUnfinishedModel->setHeaderData(8, Qt::Horizontal, QObject::tr("是否出技术协议"));
    weekplansUnfinishedModel->setHeaderData(9, Qt::Horizontal, QObject::tr("是否完成"));
    weekplansUnfinishedModel->setHeaderData(10, Qt::Horizontal, QObject::tr("所用工时"));
    weekplansUnfinishedModel->setHeaderData(11, Qt::Horizontal, QObject::tr("完成日期"));
    weekplansUnfinishedModel->setHeaderData(12, Qt::Horizontal, QObject::tr("延期原因"));
    weekplansUnfinishedModel->setHeaderData(13, Qt::Horizontal, QObject::tr("备注"));

    //增加右键菜单
    weekplanUnfinishedTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(weekplanUnfinishedTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenu(QPoint)));

    ReadOnlyDelegate *readOnlyDelegate = new ReadOnlyDelegate;
    weekplanUnfinishedTableView->setItemDelegateForColumn(1, readOnlyDelegate);
    CalendarDelegate *calendarDelegate = new CalendarDelegate;
    weekplanUnfinishedTableView->setItemDelegateForColumn(2, calendarDelegate);
    weekplanUnfinishedTableView->setItemDelegateForColumn(3, calendarDelegate);
    weekplanUnfinishedTableView->setItemDelegateForColumn(11, calendarDelegate);

    ComboBoxDelegate *comboBoxDelegate = new ComboBoxDelegate;
    weekplanUnfinishedTableView->setItemDelegateForColumn(7, comboBoxDelegate);
    weekplanUnfinishedTableView->setItemDelegateForColumn(8, comboBoxDelegate);
    weekplanUnfinishedTableView->setItemDelegateForColumn(9, comboBoxDelegate);


}

void MainWidget::addContact(QModelIndex)
{
    int rowNum = contactsModel->rowCount();
    contactsModel->insertRow(rowNum);
    contactsModel->submitAll();
}


void MainWidget::changeStack(QTreeWidgetItem *item, int)
{
    if (item == contactItem)
        stackWidget->setCurrentWidget(contactTableView);
    else if (item == projectInfoItem) {
        stackWidget->setCurrentWidget(projectInfoTableView);
    }
    else if (item == customerItem)
        stackWidget->setCurrentWidget(customerTableView);
    else if (item == weekplanItem1) {
        //过滤数据
        weekplansUnfinishedModel->setFilter(QString("engineer='%1' and finished='否'").arg(user->getName()));
        //绑定数据
        weekplanUnfinishedTableView->setModel(weekplansUnfinishedModel);
        //隐藏id列
        weekplanUnfinishedTableView->setColumnHidden(0, true);
        //设置列宽
        weekplanUnfinishedTableView->resizeColumnsToContents();
        weekplanUnfinishedTableView->setColumnWidth(5, 230);

        stackWidget->setCurrentWidget(weekplanUnfinishedTableView);
        treeWidget->hide();
        arrowWidget->show();
    } else if (item == weekplanItem2) {
        //过滤数据
        weekplansFinishedModel->setFilter(QString("engineer='%1' and finished='是'").arg(user->getName()));
        //绑定数据
        weekplanFinishedTableView->setModel(weekplansFinishedModel);
        weekplanFinishedTableView->resizeColumnsToContents();
        //隐藏id列
        weekplanFinishedTableView->setColumnHidden(0, true);
        //设置整个表不能编辑
        weekplanFinishedTableView->setEditTriggers(QTableView::NoEditTriggers);
        stackWidget->setCurrentWidget(weekplanFinishedTableView);
        treeWidget->hide();
        arrowWidget->show();
    } else if (item == scheduleItem) {
        stackWidget->setCurrentWidget(scheduleTableView);
        scheduleTableView->updateData();
        treeWidget->hide();
        arrowWidget->show();
    } else if (item == scheduleUpdateItem) {
        stackWidget->setCurrentWidget(scheduleUpdateTableView);
        scheduleUpdateTableView->updateData();
        treeWidget->hide();
        arrowWidget->show();
    } else if (item == newTaskItem) {
        stackWidget->setCurrentWidget(newTaskTableView);
        newTaskTableView->updateData();
        treeWidget->hide();
        arrowWidget->show();
    } else if (item == scheduleQueryItem) {
        stackWidget->setCurrentWidget(scheduleQueryWidget);
    }

}

void MainWidget::customContextMenu(QPoint) {
    menu = new QMenu;
    menu->addAction(QString(tr("增加新记录")), this, SLOT(slotAdd()));
    menu->addAction(QString(tr("删除当前记录")), this, SLOT(slotDelete()));
    qDebug() << "菜单";
    menu->exec(QCursor::pos());
}

void MainWidget::slotAdd()
{
    QTreeWidgetItem *tmpItem = treeWidget->currentItem();

    QTableView *tmpTableView = static_cast<QTableView*>(stackWidget->currentWidget());
    QSqlTableModel *currentModel = static_cast<QSqlTableModel*>(tmpTableView->model());
    int rowNum = currentModel->rowCount();

    if (tmpItem == weekplanItem2) {
        QMessageBox::critical(this, QString("禁止添加新列"), QString("请在未完成周计划中添加新列"));
    } else if (tmpItem == weekplanItem1){
        static_cast<QTableView*>(stackWidget->currentWidget())->model()->insertRow(rowNum);
        static_cast<WeekplanModel*>(static_cast<QTableView*>(stackWidget->currentWidget())->model())->setData(currentModel->index(rowNum, 1), user->getName());
        static_cast<WeekplanModel*>(static_cast<QTableView*>(stackWidget->currentWidget())->model())->submitAll();
    } else
        static_cast<QTableView*>(stackWidget->currentWidget())->model()->insertRow(rowNum);

}

void MainWidget::slotDelete()
{
    QModelIndex index = static_cast<QTableView*>(stackWidget->currentWidget())->currentIndex();
    int row = index.row();
    static_cast<QTableView*>(stackWidget->currentWidget())->model()->removeRow(row);
}

void MainWidget::arrowWidget_slot()
{
    arrowWidget->hide();
    treeWidget->show();
}

void MainWidget::query_slot(int idx1, QString str1, int idx2, QString str2, bool flags)
{
    scheduleQueryTableView->scheduleFilter(idx1, str1, idx2, str2, flags);
    stackWidget->setCurrentWidget(scheduleQueryTableView);
    treeWidget->hide();
    arrowWidget->show();
}

