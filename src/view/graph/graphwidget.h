#ifndef CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_
#define CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_

#include <QWidget>
#include <QVector>
#include <vector>
#include "../qcustomplot/qcustomplot.h"
#include "../../common/strategy.h"
#include "../view_constants.h"

namespace s21
{

/**
 * @brief Widget for displaying error graph using qciustomplot
 */
class GraphWidget : public QWidget
{
public:
    /**
     * @brief Construct a new Graph Widget object
     * 
     * @param x_label 
     * @param y_label 
     * @param parent 
     */
    GraphWidget(QString x_label, QString y_label, QWidget* parent = nullptr);
    ~GraphWidget();

    /**
     * @brief Push a new value to the graph
     * 
     * @param value 
     */
    void PushBack(double value);

    /**
     * @brief Set the X Range object
     * 
     * @param lower 
     * @param upper 
     */
    void SetXRange(double lower, double upper);

    /**
     * @brief Set the Y Range object
     * 
     * @param lower 
     * @param upper 
     */
    void SetYRange(double lower, double upper);

    /**
     * @brief Clear the graph
     * 
     */
    void Clear();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QCustomPlot* custom_plot_{ nullptr };
    QCPGraph* graph_{ nullptr };
    QVector<double> keys_;
    QVector<double> values_;
    unsigned int value_index_{ 0 };
    double lower_{ 1 };
    double upper_{ 0 };
};

} // namespace s21

#endif  // CPP7_MLP_VIEW_GRAPH_GRAPHWIDGET_H_
