#include "paint_widget.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    s21::PaintWidget w;
    w.show();
    return a.exec();
}
