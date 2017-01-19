#include "mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    user = User::getInstance();
    qDebug() << user->getAuthority() << "mainwidget";
    treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderLabel("项目");
    treeWidget->setStyleSheet("background-color: #5B6771; font-size:17px; color:white");

    stackWidget = new QStackedWidget();

    contacts();
    customers();
    weekplans();


    stackWidget->addWidget(contactTableView);
    stackWidget->addWidget(customerTableView);
    stackWidget->addWidget(weekplanTableView);


    item1 = new QTreeWidgetItem(QStringList("供应商联系方式"));
    item2 = new QTreeWidgetItem(QStringList("协众客户"));
    item3 = new QTreeWidgetItem(QStringList("周计划"));

    treeWidget->addTopLevelItem(item1);
    treeWidget->addTopLevelItem(item2);
    treeWidget->addTopLevelItem(item3);

    item31 = new QTreeWidgetItem(QStringList("未完成周计划"));
    item32 = new QTreeWidgetItem(QStringList("已完成周计划"));
    item3->addChild(item31);
    item3->addChild(item32);
    treeWidget->show();

    connect(treeWidget, SIGNAL(itemActivated(QTreeWidgetItem*,int)), this, SLOT(changeStack(QTreeWidgetItem*,int)));

    mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(8);
    mainLayout->addWidget(treeWidget);
    mainLayout->addWidget(stackWidget);
    mainLayout->setStretch(0, 1);
    mainLayout->setStretch(1, 2);
    setLayout(mainLayout);
}

void MainWidget::contacts()
{
    contactTableView = new QTableView;
    contactTableView->updatesEnabled();

    contactsModel = new QSqlTableModel(this);
    contactsModel->setTable(QString("contacts"));
    contactsModel->setEditStrategy(QSqlTableModel::OnRowChange);
    contactsModel->select();

    contactsModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    contactsModel->removeColumn(0);
    contactsModel->setHeaderData(1, Qt::Horizontal, QObject::tr("公司"));
    contactsModel->setHeaderData(2, Qt::Horizontal, QObject::tr("姓名"));
    contactsModel->setHeaderData(3, Qt::Horizontal, QObject::tr("职位"));
    contactsModel->setHeaderData(4, Qt::Horizontal, QObject::tr("联系电话"));
    contactsModel->setHeaderData(5, Qt::Horizontal, QObject::tr("邮箱"));

    //增加右键菜单
    contactTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(contactTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenu(QPoint)));

    //绑定数据
    contactTableView->setModel(contactsModel);
    contactTableView->resizeColumnsToContents();
}

void MainWidget::customers()
{
    customerTableView = new QTableView;
    customerTableView->updatesEnabled();

    customersModel = new QSqlTableModel(this);
    customersModel->setTable(QString("customers"));
    customersModel->setEditStrategy(QSqlTableModel::OnRowChange);
    customersModel->select();

    customersModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    customersModel->setHeaderData(1, Qt::Horizontal, QObject::tr("客户名称"));
    customersModel->setHeaderData(2, Qt::Horizontal, QObject::tr("协众驻点联系人"));
    customersModel->setHeaderData(3, Qt::Horizontal, QObject::tr("驻点电话"));
    customersModel->setHeaderData(4, Qt::Horizontal, QObject::tr("驻点邮箱"));

    customersModel->removeColumn(0);

    //增加右键菜单
    customerTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(customerTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenu(QPoint)));

    //绑定数据
    customerTableView->setModel(customersModel);
    customerTableView->resizeColumnsToContents();
}

void MainWidget::weekplans()
{
    weekplanTableView = new QTableView;
    weekplanTableView->updatesEnabled();   //是否有用-E1

    weekplansModel = new QSqlTableModel(this);
    weekplansModel->setTable(QString("weekplans"));
    weekplansModel->setEditStrategy(QSqlTableModel::OnRowChange);  //是否有用-E1
    weekplansModel->select();

    weekplansModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    weekplansModel->setHeaderData(1, Qt::Horizontal, QObject::tr("起始日期"));
    weekplansModel->setHeaderData(2, Qt::Horizontal, QObject::tr("截止日期"));
    weekplansModel->setHeaderData(3, Qt::Horizontal, QObject::tr("产品名称"));
    weekplansModel->setHeaderData(4, Qt::Horizontal, QObject::tr("周计划内容"));
    weekplansModel->setHeaderData(5, Qt::Horizontal, QObject::tr("所属项目"));
    weekplansModel->setHeaderData(6, Qt::Horizontal, QObject::tr("是否需要出图"));

    weekplansModel->removeColumn(0);

    //增加右键菜单
    weekplanTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(weekplanTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenu(QPoint)));

    //绑定数据
    weekplanTableView->setModel(weekplansModel);
    weekplanTableView->resizeColumnsToContents();



}

void MainWidget::addContact(QModelIndex)
{
    int rowNum = contactsModel->rowCount();
    contactsModel->insertRow(rowNum);
    contactsModel->submitAll();
}


void MainWidget::changeStack(QTreeWidgetItem *item, int)
{
    if (item == item1)
        stackWidget->setCurrentIndex(0);
    else if (item == item2)
        stackWidget->setCurrentIndex(1);
    else if (item == item31) {
        stackWidget->setCurrentIndex(2);

    } else if (item == item32) {
        stackWidget->setCurrentIndex(2);
    }

}

void MainWidget::customContextMenu(QPoint) {
    menu = new QMenu;
    menu->addAction(QString(tr("增加新记录")), this, SLOT(slotAdd()));
    menu->addAction(QString(tr("删除当前记录")), this, SLOT(slotDelete()));
    menu->exec(QCursor::pos());
}

void MainWidget::slotAdd()
{
    QSqlTableModel *currentModel = static_cast<QSqlTableModel*>(static_cast<QTableView*>(stackWidget->currentWidget())->model());
    int rowNum = currentModel->rowCount();
    static_cast<QTableView*>(stackWidget->currentWidget())->model()->insertRow(rowNum);
}

void MainWidget::slotDelete()
{
    QModelIndex index = static_cast<QTableView*>(stackWidget->currentWidget())->currentIndex();
    int row = index.row();
    static_cast<QTableView*>(stackWidget->currentWidget())->model()->removeRow(row);
}
