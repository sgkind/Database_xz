#include "mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderLabel("项目");

    stackWidget = new QStackedWidget();

    contacts();
    customers();



    stackWidget->addWidget(contactTableView);
    stackWidget->addWidget(customerTableView);

    item1 = new QTreeWidgetItem(QStringList("供应商联系方式"));
    item2 = new QTreeWidgetItem(QStringList("协众客户"));
    item3 = new QTreeWidgetItem(QStringList("周计划"));

    treeWidget->addTopLevelItem(item1);
    treeWidget->addTopLevelItem(item2);
    treeWidget->addTopLevelItem(item3);

    QTreeWidgetItem *item31 = new QTreeWidgetItem(QStringList("child1"));
    QTreeWidgetItem *item32 = new QTreeWidgetItem(QStringList("child2"));
    item3->addChild(item31);
    item3->addChild(item32);
    treeWidget->show();

    //connect(treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(changeStack(QTreeWidgetItem*, int)));
    connect(treeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), this, SLOT(changeStack(QTreeWidgetItem*,QTreeWidgetItem*)));

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

    contactsModel = new QSqlTableModel(this);
    contactsModel->setTable(QString("contacts"));
    contactsModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    contactsModel->select();

    contactsModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    contactsModel->removeColumn(0);
    contactsModel->setHeaderData(1, Qt::Horizontal, QObject::tr("公司"));
    contactsModel->setHeaderData(2, Qt::Horizontal, QObject::tr("姓名"));
    contactsModel->setHeaderData(3, Qt::Horizontal, QObject::tr("职位"));
    contactsModel->setHeaderData(4, Qt::Horizontal, QObject::tr("联系电话"));
    contactsModel->setHeaderData(5, Qt::Horizontal, QObject::tr("邮箱"));

    contactTableView->setModel(contactsModel);
    contactTableView->resizeColumnsToContents();
    connect(contactTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(addContact(QModelIndex)));
}

void MainWidget::customers()
{
    customerTableView = new QTableView;

    customersModel = new QSqlTableModel(this);
    customersModel->setTable(QString("customers"));
    customersModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    customersModel->select();

    customersModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    customersModel->setHeaderData(1, Qt::Horizontal, QObject::tr("客户名称"));
    customersModel->setHeaderData(2, Qt::Horizontal, QObject::tr("协众驻点联系人"));
    customersModel->setHeaderData(3, Qt::Horizontal, QObject::tr("驻点电话"));
    customersModel->setHeaderData(4, Qt::Horizontal, QObject::tr("驻点邮箱"));

    customersModel->removeColumn(0);

    customerTableView->setModel(customersModel);
    customerTableView->resizeColumnsToContents();
}





void MainWidget::addContact(QModelIndex)
{
    int rowNum = contactsModel->rowCount();
    contactsModel->insertRow(rowNum);
    contactsModel->submitAll();
}


void MainWidget::changeStack(QTreeWidgetItem *, QTreeWidgetItem * itema)
{
    qDebug() << "heare";
    if (itema == item1)
        stackWidget->setCurrentIndex(1);
    else if (itema == item2)
        stackWidget->setCurrentIndex(2);

}
