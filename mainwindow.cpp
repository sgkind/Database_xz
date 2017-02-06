#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("电子电器组数据库"));

    mainWidget = new MainWidget(this);
    setCentralWidget(mainWidget);

    createActions();
    createMenus();
    resize(1200, 600);
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
    exitAction = new QAction(tr("退出"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出程序"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    addAction = new QAction(tr("增加记录"), this);
    addAction->setShortcut(tr("Ctrl+A"));
    addAction->setStatusTip(tr("增加一条记录"));
    connect(addAction, SIGNAL(triggered()), this, SLOT(AddRecord()));

    deleteAction = new QAction(tr("删除记录"), this);
    deleteAction->setShortcut(tr("Ctrl+D"));
    deleteAction->setStatusTip(tr("删除记录"));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(DeleteRecord()));

    changePwdAction = new QAction(tr("修改密码"), this);
    changePwdAction->setShortcut(tr("Ctrl+M"));
    changePwdAction->setStatusTip(tr("修改密码"));
    connect(changePwdAction, SIGNAL(triggered()), this, SLOT(ChangePassword()));

    addUserAction = new QAction(tr("添加用户"), this);
    addUserAction->setShortcut(tr("Ctrl+U"));
    addUserAction->setStatusTip(tr("添加新用户"));
    if (user->getAuthority() != 0) {
        addUserAction->setDisabled(true);
    }
    connect(addUserAction, SIGNAL(triggered()), this, SLOT(AddUser()));

    deleteUserAction = new QAction(tr("删除用户"), this);
    deleteUserAction->setShortcut(tr("Ctrl+Y"));
    deleteUserAction->setStatusTip(tr("删除用户"));
    if (user->getAuthority() != 0) {
        deleteUserAction->setDisabled(true);
    }
    connect(deleteUserAction, SIGNAL(triggered()), this, SLOT(DeleteUser()));

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("编辑"));
    editMenu->addAction(addAction);
    editMenu->addAction(deleteAction);

    userMenu = menuBar()->addMenu(tr("用户管理"));
    userMenu->addAction(changePwdAction);
    userMenu->addSeparator();
    userMenu->addAction(addUserAction);
    userMenu->addAction(deleteUserAction);
}

void MainWindow::AddRecord()
{
    qDebug() << "addRecord()";
}

void MainWindow::DeleteRecord()
{
    qDebug() << "DeleteRecord()";
}

void MainWindow::ChangePassword()
{
    ChangePwd changePwd;
    changePwd.exec();
}

void MainWindow::AddUser()
{

}

void MainWindow::DeleteUser()
{

}

