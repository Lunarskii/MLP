#pragma once

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include <QColor>
#include <QMouseEvent>
#include "../../common/metrics.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

namespace s21 {

struct Style {
    inline static unsigned int indent = 35;
    inline static unsigned int axes_size = 3;
    inline static unsigned int axes_text_size = 10;
    inline static unsigned int metrics_text_size = 12;
    inline static QColor background_color = QColor(15, 15, 15);
    inline static QColor axes_color = QColor(184, 134, 11);
    inline static QColor accuracy_color = QColor(132, 169, 141);
    inline static QColor precision_color = QColor(174, 124, 124);
    inline static QColor recall_color = QColor(92, 108, 124);
    inline static QColor f1_color = QColor(149, 149, 149);
    inline static QColor axes_text_color = QColor(184, 134, 11);
    inline static double chart_size_coef = 0.5;
    inline static unsigned int grid_size = 1;
    inline static QColor grid_color = Qt::white;
    inline static unsigned int grid_number = 10;
};

class MetricsWidget : public QWidget {
    Q_OBJECT

    public:
        MetricsWidget(QWidget *parent = nullptr);
        virtual ~MetricsWidget() = default;

        void SetMetrics(Metrics &m);
        

        void Clear();

    protected:
        void paintEvent(QPaintEvent *event) override;
        void resizeEvent(QResizeEvent *event) override;
        void mouseDoubleClickEvent(QMouseEvent *event) override;

    private:

        QImage image_;
        QPainter painter_;

        bool classes_ = false;

        std::vector<Metrics> metrics_;
        unsigned int height_, width_;

        void DrawCrossCharts();
        void DrawClassCharts();
        void Draw();
        void DrawAxes();
        int ChartHeight(double value);

};

} // namespace s21
