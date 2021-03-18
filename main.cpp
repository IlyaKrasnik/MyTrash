#include "mainwindow.h"
#include "player.h"
#include "boost.h"

#include <QApplication>
#include <fstream>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>

int main(int argc, char *argv[])
{
//    for (int j = 1; j <= 10; j++) {
//        Boost b(j);
//        for (int i = 0; i < 10000; i++) {
//            if (b.getGrowth() >= b.getPrice())
//                return 1;
//            std::cout << b << std::endl;
//            b.UpdateForLevel();
//        }
//    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    return 0;
}
