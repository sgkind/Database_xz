#include "scheduletableview.h"

ScheduleTableView::ScheduleTableView(bool _update) : QTableView()
{
    update = _update;
    user = User::getInstance();
    setEditTriggers(QTableView::NoEditTriggers);
    QFont font;
    font.setPointSize(fontSize);
    setFont(font);

    headerStr << QString("编号") << QString("客户项目号") << QString("协众项目号") << QString("电器负责人")
              << QString("产品负责人") << QString("产品名称") << QString("供应商") << QString("产品定点")
              << QString("产品定点") << QString("技术协议") << QString("技术协议") << QString("S1图下发")
              << QString("S1图下发") << QString("RP件试装") << QString("RP件试装") << QString("设计冻结")
              << QString("设计冻结") << QString("S3图下发") << QString("S3图下发") << QString("DVP签署")
              << QString("DVP签署") << QString("首模件送样") << QString("首模件送样") << QString("OTS认可")
              << QString("OTS认可") << QString("A图下发") << QString("A图下发") << QString("备注");

    scheduleModel = new ScheduleModel(this);

}

ScheduleTableView::~ScheduleTableView()
{

}

void ScheduleTableView::updateData()
{
    scheduleModel->setTable(QString("jobs"));


    for (int i = 0; i < headerStr.length(); ++i)
        scheduleModel->setHeaderData(i, Qt::Horizontal, headerStr.at(i));

    scheduleModel->setFilter(QString("pengineer='%1'").arg(user->getName()));
    scheduleModel->select();

    //绑定数据
    setModel(scheduleModel);
    //隐藏各列
    setColumnHidden(0, true);
    int i = update ? 7 : 8;
    for (; i < 27; i += 2)
        setColumnHidden(i, true);

    //设置列宽
    resizeColumnsToContents();

    //设置显示代理
    if (update) {
        CheckBoxDelegate *checkBoxDelegate = new CheckBoxDelegate;

        for (int j = 8; j < 27; j += 2)
            setItemDelegateForColumn(j, checkBoxDelegate);
        scheduleModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    }

}
