#include <QCoreApplication>
#include "tester.hpp"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
