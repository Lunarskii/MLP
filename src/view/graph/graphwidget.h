#ifndef CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_
#define CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_

#include <QWidget>
#include <QVector>
#include <vector>
#include "../qcustomplot/qcustomplot.h"

namespace s21
{

class GraphWidget : public QWidget
{
public:
    GraphWidget(QWidget* parent = nullptr);
    ~GraphWidget();
    void LoadEpochs(std::vector<double>* errors);
    void LoadEpoch(double error);

private:
    QCustomPlot* custom_plot_{ nullptr };
    std::vector<double> errors_;
};

} // namespace s21

#endif  // CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_
