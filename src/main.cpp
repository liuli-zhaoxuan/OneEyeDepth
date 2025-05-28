#include "test.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    // 应用程序对象，在一个qt应用程序中，该对象只有一个
    QApplication a(argc, argv);
    // 窗口对象，test继承了QMainWindow
    test w;
    // 显示窗口
    w.show();
    // 阻塞函数
    return a.exec();
}