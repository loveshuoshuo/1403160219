#include "scorewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScoreWindow w;
    w.setWindowTitle("绩点计算器");
    w.setMinimumSize(700,500);
    w.show();

    return a.exec();
}
