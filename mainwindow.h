#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>

#include "mainwidget.h"
#include "user.h"
#include "changepwd.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createActions();          //创建动作
    void createMenus();            //创建菜单

private:
    MainWidget *mainWidget;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *userMenu;
    QMenu *helpMenu;

    QAction *exitAction;
    QAction *addAction;
    QAction *deleteAction;
    QAction *changePwdAction;
    QAction *addUserAction;
    QAction *deleteUserAction;

    User *user = User::getInstance();

private slots:
    void AddRecord();
    void DeleteRecord();
    void ChangePassword();
    void AddUser();
    void DeleteUser();
};

#endif // MAINWINDOW_H
