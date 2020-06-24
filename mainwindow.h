#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLCDNumber>
#include<QLabel>
#include<sub.h>
#include<QPushButton>

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);//构造函数
    ~MainWindow();//析构函数
    void paintEvent(QPaintEvent *);//画时钟函数
public:
    void dealsub();//转换为子窗口
    void changeback();//转换为主窗口
private:
    sub w;//子窗口
    QPushButton b;//按钮
};
#endif // MAINWINDOW_H
