#include "laboratory.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Laboratory w;
    w.show();

    return a.exec();
}
