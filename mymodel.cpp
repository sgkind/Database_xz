#include "mymodel.h"
#include <QColor>
#include <QFont>
#include <QDate>
#include <QDebug>

MyModel::MyModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

}

MyModel::~MyModel()
{

}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlTableModel::data(index, role);

    //修改对齐方式
    if (Qt::TextAlignmentRole == role)
    {
        value = int(Qt::AlignCenter | Qt::AlignHCenter);
        return value;
    }

    //修改前景色
    if (Qt::ForegroundRole == role)
    {
        if (index.column())
            return QVariant(QColor(0, 0, 0));
    }

    //修改字体
    if (Qt::FontRole == role)
    {
        QFont font;
        font.setPointSize(fontSize);
        return QVariant(font);
    }

    return value;

}

WeekplanModel::WeekplanModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

}

WeekplanModel::~WeekplanModel()
{

}

QVariant WeekplanModel::data(const QModelIndex &idx, int role) const
{
    QVariant value = QSqlTableModel::data(idx, role);

    //修改对齐方式
    if (Qt::TextAlignmentRole == role)
    {
        value = int(Qt::AlignCenter | Qt::AlignHCenter);
        return value;
    }

    //修改前景色
    if (Qt::ForegroundRole == role)
    {
        if (idx.column())
            return QVariant(QColor(0, 0, 0));
    }

    //修改字体
    if (Qt::FontRole == role)
    {
        QFont font;
        font.setPointSize(fontSize);
        return QVariant(font);
    }

    return value;
}


ScheduleModel::ScheduleModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

}

ScheduleModel::~ScheduleModel()
{

}

QVariant ScheduleModel::data(const QModelIndex &idx, int role) const
{
    QVariant value = QSqlTableModel::data(idx, role);

    //修改对齐方式
    if (Qt::TextAlignmentRole == role)
    {
        value = int(Qt::AlignCenter | Qt::AlignHCenter);
        return value;
    }

    //修改前景色
    if (Qt::ForegroundRole == role)
    {
        if (idx.column())
            return QVariant(QColor(0, 0, 0));
    }

    //修改背景色
    if (Qt::BackgroundColorRole == role)
    {

        int column = idx.column();
        if ( column >= 7 && column <= 25 && column % 2 == 1){
            QDate modelDate = idx.model()->data(idx, Qt::EditRole).toDate();
            QDate curDate = QDate::currentDate();
            QModelIndex after = idx.sibling(idx.row(), idx.column()+1);
            if ((idx.model()->data(after, Qt::EditRole).toInt() == 0) && (modelDate < curDate))
                return QVariant(QColor(255, 0, 0));
            else if (idx.model()->data(after, Qt::EditRole).toInt() == 1)
                return QVariant(QColor(0, 255, 0));
        }
        return QVariant(QColor(255, 255, 255));

    }

    //修改字体
    if (Qt::FontRole == role)
    {
        QFont font;
        font.setPointSize(fontSize);
        return QVariant(font);
    }

    return value;
}

