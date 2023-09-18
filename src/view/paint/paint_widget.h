#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QImage>
#include <QPainter>
#include <QPainterPath>
#include <QFileDialog>
#include "../../common/types.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PaintWidget; }
QT_END_NAMESPACE

namespace s21 {

/**
 * @brief Widget for drawing letters
 */
class PaintWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Paint Widget object
     * 
     * @param parent 
     */
    PaintWidget(QWidget *parent = nullptr);

    ~PaintWidget();

    /**
     * @brief Set the Predict object to label
     * 
     * @param c 
     */
    void SetPredict(char c);

signals:
    /**
     * @brief Signal to send image to the model
     * 
     * @param image is a pixel vector
     */
    void SendImage(std::vector<double> image);

private:
    Ui::PaintWidget *ui_;
};

/**
 * @brief Widget for drawing letters
 */
class ImageWidget : public QWidget 
{
public:
    /**
     * @brief Construct a new Image Widget object
     * 
     * @param parent 
     */
    ImageWidget(QWidget* parent = nullptr);

    /**
     * @brief Get the Pen object
     * 
     * @return QPen& 
     */
    QPen& GetPen();

    /**
     * @brief Clear the image
     * 
     */
    void Clear();

    /**
     * @brief Load image from file
     * 
     * @param file_path 
     */
    void LoadImage(QString file_path);

    /**
     * @brief Save image to file
     * 
     * @param file_path 
     */
    void SaveImage(QString file_path);
    std::vector<fp_type> GetImage();

protected:
    /**
     * @brief Start drawing
     * 
     * @param event 
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief Draw
     * 
     * @param event 
     */
    void mouseMoveEvent(QMouseEvent *event) override;

    /**
     * @brief Stop drawing
     * 
     * @param event 
     */
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void Draw();

private:
    QImage image_;
    QImage prev_image_;
    QPainter painter_;
    QPainterPath path_;
    QPen pen_;  
    bool drawing_ = false;
};

} // namespace s21
