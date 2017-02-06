#ifndef MYMODEL_H
#define MYMODEL_H

#include <QSqlTableModel>

const int fontSize = 10;

class MyModel : public QSqlTableModel
{
public:
    MyModel(QObject *parent = 0, QSqlDatabase db = QSqlDatabase());
    ~MyModel();
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

class WeekplanModel : public QSqlTableModel
{
public:
    WeekplanModel(QObject *parent = 0, QSqlDatabase db = QSqlDatabase());
    ~WeekplanModel();
    QVariant data(const QModelIndex &idx, int role) const;
};

class ScheduleModel : public QSqlTableModel
{
public:
    ScheduleModel(QObject *parent = 0, QSqlDatabase db = QSqlDatabase());
    ~ScheduleModel();
    QVariant data(const QModelIndex &idx, int role) const;
};

#endif // MYMODEL_H
