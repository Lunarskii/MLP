#include "metrics_widget.h"

using namespace s21;

MetricsWidget::MetricsWidget(QWidget *parent) :
        QWidget(parent), image_(QSize(1, 1), QImage::Format_RGB32)  {

    image_.fill(Style::background_color);

}

void MetricsWidget::SetMetrics(Metrics &m) {
    metrics_.push_back(m);
    Draw();
}

void MetricsWidget::paintEvent(QPaintEvent *event) {
    QPainter(this).drawImage(0, 0, image_);
    QWidget::paintEvent(event);
}

void MetricsWidget::resizeEvent(QResizeEvent *event) {
    height_ = event->size().height();
    width_ = event->size().width();
    image_ = image_.scaled(event->size(), Qt::IgnoreAspectRatio);
    QWidget::resizeEvent(event);
    Draw();
}

void MetricsWidget::DrawCrossCharts() {
    unsigned int size = metrics_.size();
    int w = width_ - 2 * Style::indent;
    int chart_size = 0.25 * Style::chart_size_coef * w / size;
    int x = w / (size + 1) - 1.5 * chart_size + Style::indent;
    int step = w / (size + 1) - 3 * chart_size;
    int y_low = height_ - Style::indent - chart_size * 0.5;

    for (unsigned int i = 0; i < size; x += step) {
        painter_.setPen(QPen(Style::accuracy_color, chart_size));
        painter_.drawLine(x, y_low, x, ChartHeight(metrics_[i].accuracy));

        x += chart_size;
        painter_.setPen(QPen(Style::precision_color, chart_size));
        painter_.drawLine(x, y_low, x, ChartHeight(Func::MeanError(metrics_[i].precision)));

        x += chart_size;
        painter_.setPen(QPen(Style::recall_color, chart_size));
        painter_.drawLine(x, y_low, x, ChartHeight(Func::MeanError(metrics_[i].recall)));

        x += chart_size;
        painter_.setPen(QPen(Style::f1_color, chart_size));
        painter_.drawLine(x, y_low, x, ChartHeight(Func::MeanError(metrics_[i].F1)));

        painter_.setPen(QPen(Style::axes_text_color, Style::axes_text_size));
        painter_.drawText(x - chart_size * 1.5, height_ - Style::indent * 0.5, QString::number(++i));
    }

    // draw metrics names
    painter_.setPen(QPen(Style::accuracy_color, Style::metrics_text_size));
    painter_.drawText(0.2 * w, Style::indent * 0.5, "Accuracy");

    painter_.setPen(QPen(Style::precision_color, Style::metrics_text_size));
    painter_.drawText(0.4 * w, Style::indent * 0.5, "Precision");

    painter_.setPen(QPen(Style::recall_color, Style::metrics_text_size));
    painter_.drawText(0.6 * w, Style::indent * 0.5, "Recall");

    painter_.setPen(QPen(Style::f1_color, Style::metrics_text_size));
    painter_.drawText(0.8 * w, Style::indent * 0.5, "F1");
}

int MetricsWidget::ChartHeight(double value) {
    return height_ - Style::indent - value * (height_ - 2 * Style::indent);
}


void MetricsWidget::DrawAxes() {
    // draw gorizontal line
    painter_.setPen(QPen(Style::axes_color, Style::axes_size));
    int y = height_ - Style::indent;
    painter_.drawLine(Style::indent,
                        y,
                        width_ - Style::indent,
                        y);
    
    // draw vertical line
    int x = Style::indent;
    painter_.drawLine(x,
                        Style::indent,
                        x,
                        height_ - Style::indent);
    
    painter_.setPen(QPen(Style::grid_color, Style::grid_size));

    // draw gorizontal grid
    for (int k = 0; k < Style::grid_number; ++k) {
        painter_.drawLine(x,
                            Style::indent + k * (height_ - 2 * Style::indent) / Style::grid_number,
                            width_ - Style::indent,
                            Style::indent + k * (height_ - 2 * Style::indent) / Style::grid_number);
    }

    // draw y axis text
    double step = 1.0 / Style::grid_number;
    painter_.setPen(QPen(Style::axes_text_color, Style::axes_text_size));
    for (int k = 0; k < Style::grid_number; ++k) {
        painter_.drawText(Style::indent * 0.2,
                            Style::indent + k * (height_ - 2 * Style::indent) / Style::grid_number,
                            QString::number(1.0 - k * step, 'f', 1));
    }
}

void MetricsWidget::DrawClassCharts() {
    
    const unsigned int size = 26;
    unsigned int metrics_size = metrics_.size();

    int w = width_ - 2 * Style::indent;
    int chart_size = 0.333 * Style::chart_size_coef * w / size;
    int x = w / (size + 1) - chart_size + Style::indent;
    int step = w / (size + 1) - 2 * chart_size;
    int y_low = height_ - Style::indent - chart_size * 0.5;

    std::vector<float> mean_recall(size), mean_precision(size), mean_f1(size);
    for (int k = 0; k < metrics_size; ++k) {
        for (int g = 0; g < 26; ++g) {
            mean_recall[g] += metrics_[k].recall[g];
            mean_precision[g] += metrics_[k].precision[g];
            mean_f1[g] += metrics_[k].F1[g];
        }
    }

    for (unsigned int i = 0; i < size; x += step) {
        painter_.setPen(QPen(Style::precision_color, chart_size));
        painter_.drawLine(x, y_low, x, ChartHeight(mean_precision[i] / metrics_size));

        x += chart_size;
        painter_.setPen(QPen(Style::recall_color, chart_size));
        painter_.drawLine(x, y_low, x, ChartHeight(mean_recall[i] / metrics_size));

        x += chart_size;
        painter_.setPen(QPen(Style::f1_color, chart_size));
        painter_.drawLine(x, y_low, x, ChartHeight(mean_f1[i] / metrics_size));

        painter_.setPen(QPen(Style::axes_text_color, Style::axes_text_size));
        painter_.drawText(x - chart_size * 1.5, height_ - Style::indent * 0.5, QString((char)(i++ + 'A')));
    }

    // draw metrics names
    painter_.setPen(QPen(Style::precision_color, Style::metrics_text_size));
    painter_.drawText(0.25 * w, Style::indent * 0.5, "Precision");

    painter_.setPen(QPen(Style::recall_color, Style::metrics_text_size));
    painter_.drawText(0.5 * w, Style::indent * 0.5, "Recall");

    painter_.setPen(QPen(Style::f1_color, Style::metrics_text_size));
    painter_.drawText(0.75 * w, Style::indent * 0.5, "F1");

}

void MetricsWidget::Draw() {
    if (metrics_.empty()) {
        return;
    }
    image_.fill(Style::background_color);
    painter_.begin(&image_);
    DrawAxes();

    if (classes_) {
        DrawClassCharts();
    } else {
        DrawCrossCharts();
    }

    painter_.end();
    // update();
    repaint();
}

void MetricsWidget::Clear() {
    metrics_.clear();
    image_.fill(Style::background_color);
    update();
}

void MetricsWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        classes_ = !classes_;
        Draw();
    }
}

