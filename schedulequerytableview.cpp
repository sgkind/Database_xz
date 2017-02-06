#include "schedulequerytableview.h"
#include <QDebug>

ScheduleQueryTableView::ScheduleQueryTableView()
{
    setEditTriggers(QTableView::NoEditTriggers);
    QFont font;
    font.setPointSize(fontSize);
    setFont(font);

    scheduleQueryModel = new ScheduleModel(this);


    strList << tr("pengineer") << tr("eengineer") << tr("xzno") << tr("cpno");
    checkBoxDelegateNoEditor = new CheckBoxDelegateNoEditor;


}

void ScheduleQueryTableView::scheduleFilter(int idx1, QString str1, int idx2, QString str2, bool flags)
{
    scheduleQueryModel->setTable(QString("jobs"));
    scheduleQueryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    scheduleQueryModel->setHeaderData(1, Qt::Horizontal, QObject::tr("客户项目号"));
    scheduleQueryModel->setHeaderData(2, Qt::Horizontal, QObject::tr("协众项目号"));
    scheduleQueryModel->setHeaderData(3, Qt::Horizontal, QObject::tr("电器负责人"));
    scheduleQueryModel->setHeaderData(4, Qt::Horizontal, QObject::tr("产品负责人"));
    scheduleQueryModel->setHeaderData(5, Qt::Horizontal, QObject::tr("产品名称"));
    scheduleQueryModel->setHeaderData(6, Qt::Horizontal, QObject::tr("供应商"));
    scheduleQueryModel->setHeaderData(7, Qt::Horizontal, QObject::tr("产品定点"));
    scheduleQueryModel->setHeaderData(8, Qt::Horizontal, QObject::tr("是否完成"));
    scheduleQueryModel->setHeaderData(9, Qt::Horizontal, QObject::tr("技术协议"));
    scheduleQueryModel->setHeaderData(10, Qt::Horizontal, QObject::tr("是否完成"));
    scheduleQueryModel->setHeaderData(11, Qt::Horizontal, QObject::tr("S1图下发"));
    scheduleQueryModel->setHeaderData(12, Qt::Horizontal, QObject::tr("是否完成"));
    scheduleQueryModel->setHeaderData(13, Qt::Horizontal, QObject::tr("RP件试装"));
    scheduleQueryModel->setHeaderData(14, Qt::Horizontal, QObject::tr("是否完成"));
    scheduleQueryModel->setHeaderData(15, Qt::Horizontal, QObject::tr("设计冻结"));
    scheduleQueryModel->setHeaderData(16, Qt::Horizontal, QObject::tr("是否完成"));
    scheduleQueryModel->setHeaderData(17, Qt::Horizontal, QObject::tr("S3图下发"));
    scheduleQueryModel->setHeaderData(18, Qt::Horizontal, QObject::tr("是否完成"));
    scheduleQueryModel->setHeaderData(19, Qt::Horizontal, QObject::tr("DVP签署"));
    scheduleQueryModel->setHeaderData(20, Qt::Horizontal, QObject::tr("是否完成"));
    scheduleQueryModel->setHeaderData(21, Qt::Horizontal, QObject::tr("首模件送样"));
    scheduleQueryModel->setHeaderData(22, Qt::Horizontal, QObject::tr("是否完成"));
    scheduleQueryModel->setHeaderData(23, Qt::Horizontal, QObject::tr("OTS认可"));
    scheduleQueryModel->setHeaderData(24, Qt::Horizontal, QObject::tr("是否完成"));
    scheduleQueryModel->setHeaderData(25, Qt::Horizontal, QObject::tr("A图下发"));
    scheduleQueryModel->setHeaderData(26, Qt::Horizontal, QObject::tr("是否完成"));
    scheduleQueryModel->setHeaderData(27, Qt::Horizontal, QObject::tr("备注"));

    QString queryStr;
    if (idx1 >= 0)
        queryStr += QString("%1='%2'").arg(strList.at(idx1)).arg(str1);
    if (idx2 >= 0) {
        if (idx1 >= 0)
            queryStr += " and ";
         queryStr += QString("%1='%2'").arg(strList.at(idx2)).arg(str2);
    }

    if (flags == false)
        queryStr += " and (" + QString( "dd = 0 or xy = 0 or s1 = 0 or rp = 0 or dj = 0 or s3 = 0 or dvp = 0 or smj = 0 or ots = 0") + ")";
    qDebug() << queryStr;
    scheduleQueryModel->setFilter(queryStr);
    scheduleQueryModel->select();

    setModel(scheduleQueryModel);

    resizeColumnsToContents();

    for (int i = 8; i < 27; i += 2)
        setItemDelegateForColumn(i, checkBoxDelegateNoEditor);

}

ScheduleQueryTableView::~ScheduleQueryTableView()
{

}


