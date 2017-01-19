#include "mainwindow.h"
#include "connect.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createConnection())
        return 0;
    Login dlg;

    if(dlg.exec() == QDialog::Accepted) {
        MainWindow w;
        w.show();
        return a.exec();
    } else {
        return 0;
    }
}
