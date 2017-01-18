#include "mainwindow.h"
#include "connect.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createConnection())
        return 0;
    MainWindow w;
    Login dlg;

    if(dlg.exec() == QDialog::Accepted) {
        w.show();
        return a.exec();
    } else {
        return 0;
    }
}
