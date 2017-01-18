#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTreeWidget>
#include <QStackedWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QTableView>
#include <QSqlTableModel>

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

    QTreeWidgetItem *item1;
    QTreeWidgetItem *item2;
    QTreeWidgetItem *item3;

    QHBoxLayout *mainLayout;

    void contacts();
    QSqlTableModel *contactsModel;

    void customers();
    QSqlTableModel *customersModel;

signals:

public slots:
    void addContact(QModelIndex);

    void changeStack(QTreeWidgetItem* itemb, QTreeWidgetItem* itema);
};

#endif // MAINWIDGET_H
