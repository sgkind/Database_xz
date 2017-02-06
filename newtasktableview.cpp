#include "newtasktableview.h"
#include <QDebug>

NewTaskTableView::NewTaskTableView() : QTableView()
{
    setEditTriggers(QTableView::DoubleClicked);
    QFont font;
    font.setPointSize(fontSize);
    setFont(font);

    newTaskModel = new ScheduleModel(this);
    newTaskModel->setEditStrategy(QSqlTableModel::OnFieldChange);

    headerStr << QString("编号") << QString("客户项目号") << QString("协众项目号") << QString("电器负责人")
              << QString("产品负责人") << QString("产品名称") << QString("供应商") << QString("产品定点")
              << QString("是否完成") << QString("技术协议") << QString("是否完成") << QString("S1图下发")
              << QString("是否完成") << QString("RP件试装") << QString("是否完成") << QString("设计冻结")
              << QString("是否完成") << QString("S3图下发") << QString("是否完成") << QString("DVP签署")
              << QString("是否完成") << QString("首模件送样") << QString("是否完成") << QString("OTS认可")
              << QString("是否完成") << QString("A图下发") << QString("是否完成") << QString("备注");

}

void NewTaskTableView::updateData()
{
    calendarDelegate = new CalendarDelegate;

    newTaskModel->setTable(QString("jobs"));


    for (int i = 0; i < headerStr.length(); ++i)
        newTaskModel->setHeaderData(i, Qt::Horizontal, headerStr.at(i));

    newTaskModel->select();

    setModel(newTaskModel);

    resizeColumnsToContents();

    for (int i = 7; i < 27; i += 2)
        setItemDelegateForColumn(i, calendarDelegate);
    for (int i = 8; i < 27; i += 2)
        setColumnHidden(i, true);

    setColumnHidden(0, true);


}

NewTaskTableView::~NewTaskTableView()
{

}
