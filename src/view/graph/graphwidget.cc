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
    pen.setWidth(GraphWidgetConstants::kPenWidth);
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
        lower_ = value * GraphWidgetConstants::kLowerZoomRatio;
    }
    if (value > upper_)
    {
        upper_ = value * GraphWidgetConstants::kUpperZoomRatio;
    }
    if (value_index_ != values_.size())
    {
        values_[value_index_++] = value;
        graph_->setData(keys_, values_);
        SetYRange(lower_, upper_);
        custom_plot_->replot();
    }
}

void GraphWidget::SetXRange(double lower, double upper)
{
    double step = 1.0 / Const::error_updates;
    double value = step;

    custom_plot_->xAxis->setRange(lower, upper);
    for (int i = 0; i < static_cast<int>(upper) * Const::error_updates; ++i, value += step)
    {
        keys_.push_back(value);
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
