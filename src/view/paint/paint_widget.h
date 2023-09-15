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
#include <QMessageBox>
#include "../../common/types.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PaintWidget; }
QT_END_NAMESPACE

namespace s21 {

class PaintWidget : public QWidget
{
    Q_OBJECT

public:
    PaintWidget(QWidget *parent = nullptr);
    ~PaintWidget();
    void SetPredict(char c);

signals:
    void SendImage(std::vector<double> image);

private:
    Ui::PaintWidget *ui_;
};

class ImageWidget : public QWidget 
{
public:
    ImageWidget(QWidget* parent = nullptr);
    QPen& GetPen();
    void Clear();
    void LoadImage(QString file_path);
    void SaveImage(QString file_path);
    std::vector<fp_type> GetImage();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
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
