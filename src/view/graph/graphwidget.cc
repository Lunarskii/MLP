#include "graphwidget.h"

namespace s21
{

GraphWidget::GraphWidget(QString x_label, QString y_label, QWidget* parent)
    : QWidget(parent)
    , custom_plot_(new QCustomPlot(this))
{
    custom_plot_->xAxis->setLabel(x_label);
    custom_plot_->yAxis->setLabel(y_label);
}

GraphWidget::~GraphWidget()
{
    delete custom_plot_;
}

void GraphWidget::LoadEpochs(std::vector<double>* errors)
{
    QVector<double> values(errors->begin(), errors->end());

    custom_plot_->removeGraph(0);
    custom_plot_->addGraph()->setData(keys, values);
    custom_plot_->replot();
}

// нужно будет чистить график каждый раз, как начинается новое обучение
void GraphWidget::LoadEpoch(double error)
{
    errors_.push_back(error);
    LoadEpochs(&errors_);
}

void GraphWidget::SetXRange(double lower, double upper)
{
    custom_plot_->xAxis->setRange(lower, upper);
    keys.clear();
    for (std::size_t i = 0; i < upper; ++i)
    {
        keys.push_back(static_cast<double>(i + 1));
    }
}

void GraphWidget::SetYRange(double lower, double upper)
{
    custom_plot_->yAxis->setRange(lower, upper);
}

void GraphWidget::resizeEvent(QResizeEvent *event)
{
    custom_plot_->resize(event->size().width(), event->size().height());
    QWidget::resizeEvent(event);
}

} // namespace s21
