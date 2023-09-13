#ifndef CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_
#define CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_

#include <QWidget>
#include <QVector>
#include <vector>
#include "../qcustomplot/qcustomplot.h"
#include "../../common/strategy.h"

namespace s21
{

class GraphWidget : public QWidget
{
public:
    GraphWidget(QString x_label, QString y_label, QWidget* parent = nullptr);
    ~GraphWidget();
    void PushBack(double value);
    void SetXRange(double lower, double upper);
    void SetYRange(double lower, double upper);
    void Clear();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QCustomPlot* custom_plot_{ nullptr };
    QCPGraph* graph_{ nullptr };
    QVector<double> keys_;
    QVector<double> values_;
    unsigned int value_index_{ 0 };
};

} // namespace s21

#endif  // CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_
