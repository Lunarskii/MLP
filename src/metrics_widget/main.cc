#include "metrics_widget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    s21::MetricsWidget mw;
    mw.show();
    return a.exec();
}
