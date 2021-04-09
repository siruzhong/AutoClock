# AutoClock:Qt实现 指针式时钟+数字时钟
## 1. 设计

我设计两个窗口，一个主窗口（mainwindow）一个子窗口（sub），其中主窗口用来实现基本的题目要求，有如下表所示几个模块

| MainWindow(QWidget *parent = nullptr) | 构造函数         |
| ------------------------------------- | ---------------- |
| void paintEvent(QPaintEvent *)        | 画时钟函数       |
| void dealsub()                        | 转换为子窗口函数 |
| void changeback()                     | 转换为主窗口函数 |
| sub w                                 | 子窗口的声明     |
| QPushButton b                         | 按钮的声明       |

首先利用Qt自带的时间函数QTime::currentTime()获取系统时间，然后利用**paintEvent**(QPaintEvent *)函数根据获取到的系统时间进行时针，分针，秒针的绘画，并且画出对应的小时刻度线，分钟刻度线，秒刻 度线，实现基本时钟的样式，最后加入scale()函数进行相应的比例缩放，实现时钟能随窗口的大小变化而变化；

 对于子窗口则是我自己多加入的模块，有如下表所示几个模块

| explicit sub(QWidget *parent = nullptr) | 构造函数       |
| --------------------------------------- | -------------- |
| void sentsignal()                       | 发送信号函数   |
| void paintEvent(QPaintEvent *event)     | 画电子时钟函数 |
| void mysignal()                         | 信号           |
| void showtime()                         | 显示时间函数   |
| QPushButton b1;                         | 按钮的声明     |
| QLCDNumber *lcd                         | Lcd的声明      |

该串口现实的是一个电子时钟，用一个lcd液晶显示器以”时：分：秒”的格式显示当下时间，同样是利用自带的时间函数QTime::currentTime()获取当前时间并通过lcd显示。最后将两个窗口通过两个按钮连接起来，实现互相切换功能。

## 2. 用户手册

点击运行后首先是一个指针式时钟窗口，点击Digital Clock->可以跳转到数字时钟窗口，显示的是一个数字时钟，以“时：分：秒”的格式进行显示，再点击Move Clock->可以还原为指针式时钟窗口，可以实现相互切换

## 3. 运行效果图

![image-20210409104817034](https://gitee.com/zhong_siru/images/raw/master//img/image-20210409104817034.png)
