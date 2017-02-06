#include "informationtableview.h"

informationTableView::informationTableView(QWidget *parent) : QTableView(parent)
{
    setEditTriggers(QTableView::DoubleClicked);
    QFont font;
    font.setPointSize(fontSize);
    setFont(font);

    model = new QSqlTableModel;
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    QStringList blowStr;



}

informationTableView::~informationTableView()
{

}
