#include "controller/controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    s21::MainWindow w;
    s21::Controller controller(&w);
    w.show();
    return a.exec();
}
