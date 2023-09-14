#include "graphwidget.h"

namespace s21
{

GraphWidget::GraphWidget(QString x_label, QString y_label, QWidget* parent)
    : QWidget(parent)
    , custom_plot_(new QCustomPlot(this))
{
    custom_plot_->xAxis->setLabel(x_label);
    custom_plot_->yAxis->setLabel(y_label);
    graph_ = custom_plot_->addGraph();
    QPen pen = graph_->pen();
    pen.setWidth(3);
    pen.setColor(Qt::red);
    graph_->setPen(pen);
}

GraphWidget::~GraphWidget()
{
    delete custom_plot_;
}

void GraphWidget::PushBack(double value)
{
    if (value < lower_)
    {
        lower_ = value * lower_zoom_ratio_;
    }
    if (value > upper_)
    {
        upper_ = value * upper_zoom_ratio_;
    }

    values_[value_index_++] = value;
    graph_->setData(keys_, values_);
    SetYRange(lower_, upper_);
    custom_plot_->replot();
}

void GraphWidget::SetXRange(double lower, double upper)
{
    custom_plot_->xAxis->setRange(lower, upper);
    for (double i = 1.0 / Const::error_updates; i < upper; i += 1.0 / Const::error_updates)
    {
        keys_.push_back(i);
        values_.push_back(std::numeric_limits<double>::quiet_NaN());
    }
    custom_plot_->replot();
}

void GraphWidget::SetYRange(double lower, double upper)
{
    custom_plot_->yAxis->setRange(lower, upper);
}

void GraphWidget::Clear()
{
    keys_.clear();
    values_.clear();
    value_index_ = 0;
    custom_plot_->replot();
}

void GraphWidget::resizeEvent(QResizeEvent *event)
{
    custom_plot_->resize(event->size().width(), event->size().height());
    QWidget::resizeEvent(event);
}

} // namespace s21
