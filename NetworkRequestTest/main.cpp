#include "networkrequesttest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NetworkRequestTest w;
    w.show();
    return a.exec();
}
