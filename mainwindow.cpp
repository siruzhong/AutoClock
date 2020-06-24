#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPen>
#include<QTime>
#include<QTimer>
#include<QLabel>
#include<QPushButton>
#include<QLCDNumber>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowIcon(QIcon(":/new/prefix1/v2-d858191577356128b31c88e186eea0db_r.jpg"));//设置图标
    QTimer *timer = new QTimer(this);//产生一个定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));//关联定时器的信号与槽
    timer->start(1000);//开始定时器，每一秒钟更新一次
    resize(600,600);//窗口大小
    b.setParent(this);//指定按钮父对象
    b.setGeometry(0,0,160,40);//设置按钮位置
    b.setText("Digital clock->");//设置按钮内容
    b.setStyleSheet("QPushButton{background-color: rgba(205,214,216,0);color:rgb(0,0,0);}");//设置按钮样式，rgba前三个参数同rgb，最后一个参数表示不透明度，0~1之间
    connect(&b,&QPushButton::released,this,&MainWindow::dealsub);//鼠标松开时触发，跳转到处理子窗口函数
    void(sub::*funsignal)()=&sub::mysignal;
    connect(&w,funsignal,this,&MainWindow::changeback);//关联信号与槽，实现从子窗口返回到主窗口
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *)
{
    static const QPoint hour[3] = {
        QPoint(14, 15),
        QPoint(-14, 15),
        QPoint(0, -110)
    };
    static const QPoint minute[3] = {
        QPoint(11, 13),
        QPoint(-11, 13),
        QPoint(0, -170)
    };
    static const QPoint second[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -210)
    };
    int size=qMin(width(),height());
    QTime time=QTime::currentTime();//获取系统当前时间
    QPainter p(this);//创建画家对象
    p.setRenderHint(QPainter::Antialiasing);//防止图形走样
    p.translate(width()/2,height()/2);//平移坐标系置中心
    p.scale(size/600.0,size/600.0);//缩放

    QBrush brush;//定义画刷
    brush.setColor(QColor(245,182,96));//设置画刷颜色
    brush.setStyle(Qt::SolidPattern);//设置样式


    QPen pen;//定义画笔
    pen.setWidth(18);//设置画笔宽度
    pen.setColor(QColor(205,214,216));//rgb设置颜色
    pen.setStyle(Qt::SolidLine);//设置风格
    p.setPen(pen);//将画笔交给画家
    p.drawEllipse(QPoint(0,0),280,280);//画圆
    pen.setColor(Qt::white);
    pen.setWidth(160);//设置画笔宽度
    p.setPen(pen);//将画笔交给画家
    p.drawEllipse(QPoint(0,0),160,160);//画圆
    //画时针
    p.setBrush(brush);//将画刷交给画家
    p.setPen(Qt::NoPen);
    p.save();//保存当下状态
    p.rotate(30.0*(time.hour()+time.minute()/60.0));//图形旋转，以原点为旋转中心，顺时针水平旋转对应时针的角度
    p.drawConvexPolygon(hour,3);//画时针这个凸多边形，第一个参数为所有的点，第二个参数为点的个数
    p.restore();//恢复上一次保存的结果，和save()成对出现

    //绘制小时线
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);
    pen.setColor(Qt::black);
    p.setPen(pen);
    for(int i=0;i<12;i++)
    {
        p.drawLine(0,268,0,276);//画小时线
        p.drawText(-5,-235,QString::number(i));//表明小时数
        p.rotate(30);//每画一次旋转30度
    }

    //画分针
    p.setPen(Qt::NoPen);
    p.setBrush(QColor(144,199,247));
    p.save();//保存当下状态
    p.rotate(6.0*(time.minute()+time.second()/60.0));//顺时针旋转至分针的位置
    p.drawConvexPolygon(minute,3);//画分针这个凸多边形，第一个参数为所有的点，第二个参数为点的个数
    p.restore();//恢复上一次保存的结果，和save()成对出现

    //绘制分钟线
    pen.setStyle(Qt::SolidLine);
    pen.setColor(QColor(0,0,0));
    pen.setWidth(1);
    p.setPen(pen);
    for(int i=0;i<60;i++)
    {
        if((i%5)!=0)
        p.drawLine(0,265,0,276);//5的倍数时不画，因为有小时线
        p.rotate(6);//每画一次旋转6度
    }

    //画秒线
    p.setPen(Qt::NoPen);
    p.setBrush(QColor(119,217,175));
    p.save();
    p.rotate(6*time.second());//顺时针旋转至秒针的位置
    p.drawConvexPolygon(second, 3);//画秒针这个凸多边形，第一个参数为所有的点，第二个参数为点的个数
    p.restore();

    //画圆心
    p.setBrush(Qt::black);
    p.setPen(Qt::white);
    p.save();
    p.drawEllipse(QPoint(0,0),3,3);//画圆心
    p.restore();

    //表明上午还是下午
    p.setPen(Qt::black);
    if(time.hour()>=12)
    p.drawText(-6,-50,"PM");//画文本区
    else
    p.drawText(-6,-50,"AM");//画文本区
    p.drawText(-60,-130,"Made  By  ZSR");//画文本区
}

void MainWindow::dealsub()
{
    w.show();//显示子窗口
    this->hide();//主窗口隐藏
}

void MainWindow::changeback()
{
    w.hide();//子窗口隐藏
    this->show();//显示主窗口L
}

