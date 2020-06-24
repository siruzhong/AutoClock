#ifndef SUB_H
#define SUB_H

#include <QMainWindow>
#include<QPushButton>
#include<QLCDNumber>
class sub : public QMainWindow
{
    Q_OBJECT
public:
    explicit sub(QWidget *parent = nullptr);
    void sentsignal();//发送信号
    void paintEvent(QPaintEvent *event);//画电子时钟
signals://信号
    void mysignal();
public slots://槽
    void showtime();//显示时间函数
private:
    QPushButton b1;//按钮
    QLCDNumber *lcd;//lcd
};

#endif // SUB_H
