#ifndef INFORMATIONTABLEVIEW_H
#define INFORMATIONTABLEVIEW_H

#include <QTableView>
#include <QSqlTableModel>
#include <QVector>
#include <QStringList>

class informationTableView : public QTableView
{
public:
    informationTableView(QWidget *parent = 0);
    ~informationTableView();

private:
    QSqlTableModel *model;
    QVector<QStringList> headerStrs;

    int fontSize;
};

#endif // INFORMATIONTABLEVIEW_H
