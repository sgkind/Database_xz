#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("数据库"));
    mainWidget = new MainWidget(this);
    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{

}
