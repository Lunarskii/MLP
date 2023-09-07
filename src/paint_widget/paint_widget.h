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
#include "../common/types.h"


#include "../model/matrix_model.h"

#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class PaintWidget; }
QT_END_NAMESPACE

namespace s21 {

class PaintWidget;

class ImageWidget : public QWidget {
    Q_OBJECT
    friend class PaintWidget;

    public:
        ImageWidget(QWidget* parent = nullptr);
        void SetUi(Ui::PaintWidget* ui);

    protected:
        void mousePressEvent(QMouseEvent *event) override;
        void mouseMoveEvent(QMouseEvent *event) override;
        void mouseReleaseEvent(QMouseEvent *event) override;
        void paintEvent(QPaintEvent *event) override;
        void resizeEvent(QResizeEvent *event) override;

    private:
        void Draw();
        void SetPen();
        bool drawing_ = false;
        Ui::PaintWidget *ui_;
        QImage image_, prev_image_;
        QPainter painter_;
        QPainterPath path_;
        QPen pen_;

        // TEST
        MatrixModel mm = MatrixModel("../perceptron1.prcp");
        
};

class PaintWidget : public QWidget {
    Q_OBJECT

    public:
        PaintWidget(QWidget *parent = nullptr);
        ~PaintWidget();

    private:
        Ui::PaintWidget *ui_;

};


} // namespace s21
