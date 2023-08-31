#ifndef CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_
#define CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_

#include <QWidget>
#include <QVector>
#include <vector>
#include "../QCustomPlot/qcustomplot.h"

class GraphWidget : public QWidget
{
public:
    GraphWidget(QWidget* parent = nullptr);
    ~GraphWidget();
    void LoadEpochs(std::vector<double>* errors);
private:
    QCustomPlot* custom_plot_{ nullptr };
};

#endif  // CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_
