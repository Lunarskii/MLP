#pragma once

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include <QColor>
#include <QMouseEvent>
#include "../../common/metrics.h"
#include "../view_constants.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

namespace s21 {

class MetricsWidget : public QWidget {
    Q_OBJECT

    using Style = MetricsWidgetStyle;
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

        std::vector<double> accuracy_, precision_, recall_, f1_,
                classes_precision_, classes_recall_, classes_f1_;
        unsigned int count_ = 0;


        unsigned int height_, width_;

        void DrawCrossCharts();
        void DrawClassCharts();
        void Draw();
        void DrawAxes();
        int ChartHeight(double value);

        void DrawCharts(const std::vector<QColor> &colors,
                        const std::vector<QString> &names, const std::vector<std::vector<double>*> data,
                        const std::function<QString(int)> &chart_name);

};

} // namespace s21
