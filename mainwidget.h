#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTreeWidget>
#include <QStackedWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QTableView>
#include <QSqlTableModel>
#include <QMenu>

#include "user.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);

private:
    QTreeWidget *treeWidget;
    QStackedWidget *stackWidget;

    QTableView *contactTableView;
    QTableView *customerTableView;
    QTableView *weekplanTableView;

    QTreeWidgetItem *item1;
    QTreeWidgetItem *item2;
    QTreeWidgetItem *item3;
    QTreeWidgetItem *item31;
    QTreeWidgetItem *item32;

    QHBoxLayout *mainLayout;

    void contacts();
    QSqlTableModel *contactsModel;

    void customers();
    QSqlTableModel *customersModel;

    void weekplans();
    QSqlTableModel *weekplansModel;

    QMenu *menu;

    User *user;

signals:

public slots:
    void addContact(QModelIndex);
    void slotAdd();
    void slotDelete();

    void customContextMenu(QPoint);

    void changeStack(QTreeWidgetItem* item, int);
};

#endif // MAINWIDGET_H
