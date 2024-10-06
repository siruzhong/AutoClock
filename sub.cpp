#include "sub.h"
#include<QTime>
#include<QTimer>
#include<QLCDNumber>
#include<QPainter>
sub::sub(QWidget *parent) : QMainWindow(parent)
{
    setWindowIcon(QIcon(":/new/prefix1/image3"));//设置图标
    this->setWindowTitle("Digital clock");//设置窗口标题
    this->resize(900,500);//设置窗口大小
    b1.setParent(this);//指按钮定父对象
    b1.setText("Move clock->");//设置按钮内容
    b1.setGeometry(0,0,140,40);//设置按钮位置
    b1.setStyleSheet("QPushButton{background-color: rgba(205,214,216,0);color:rgb(0,0,0);}");//设置按钮风格
    connect(&b1,&QPushButton::clicked,this,&sub::sentsignal);//连接信号与槽，当点击按钮的时候跳转到发送信号函数，主窗口接收，再执行changeback()函数，即实现了跳回主窗口
    QTimer *timer1=new QTimer(this);////产生一个定时器
    timer1->start(1000);//开始定时器，每一秒钟更新显示时间
    connect(timer1,SIGNAL(timeout()),this,SLOT(showtime()));//关联定时器的信号与槽，1s到即更新显示时间
    lcd=new QLCDNumber();//创建一个lcd液晶显示器
    lcd->setSegmentStyle(QLCDNumber::Filled);//设置显示器风格
    lcd->setParent(this);//指定显示器父对象
    lcd->move(0,50);//移动显示器位置
    lcd->setDigitCount(8);//设置所显示的位数为8位
    lcd->resize(200,50);//设置显示器大小
    showtime();//显示时间
}

void sub::sentsignal()//发送信号
{
    emit mysignal();
}

void sub::showtime()
{
    QTime time1=QTime::currentTime();//获取当前时间
    QString text=time1.toString("hh:mm:ss");//定义时间显示格式
    if((time1.second()%2)==0)
        text[5]=' ';//每2s冒号消失一次
    lcd->display(text);//lcd显示时间
}

void sub::paintEvent(QPaintEvent *event)//
{
    QPainter p(this);//创建一个画家对象
    p.drawPixmap(rect(),QPixmap(":/new/prefix1/image4.jpg"));//设置背景图
}

