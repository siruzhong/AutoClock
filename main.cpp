#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;//创建一个主窗口
    w.setWindowTitle("Move clock");//设置主窗口标题
    w.show();//显示主窗口
    return a.exec();
}
