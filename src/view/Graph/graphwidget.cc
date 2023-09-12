#include "graphwidget.h"

namespace s21
{

GraphWidget::GraphWidget(QWidget* parent)
    : QWidget(parent)
    , custom_plot_(new QCustomPlot(this))
{
    resize(500, 500);
    custom_plot_->resize(this->width(), this->height());
    custom_plot_->xAxis->setLabel("Epochs");
    custom_plot_->yAxis->setLabel("% error");
    custom_plot_->yAxis->setRange(0.0, 1.0);
}

GraphWidget::~GraphWidget()
{
    delete custom_plot_;
}

void GraphWidget::LoadEpochs(std::vector<double>* errors)
{
    QVector<double> a1;
    QVector<double> a2(errors->begin(), errors->end());

    custom_plot_->xAxis->setRange(1, errors->size());
    for (std::size_t i = 0; i < errors->size(); ++i)
    {
        a1.push_back(static_cast<double>(i + 1));
    }
    custom_plot_->removeGraph(0);
    custom_plot_->addGraph()->setData(a1, a2);
    custom_plot_->replot();
}

// нужно будет чистить график каждый раз, как начинается новое обучение
void GraphWidget::LoadEpoch(double error)
{
    errors_.push_back(error);
    LoadEpochs(&errors_);
}

} // namespace s21
