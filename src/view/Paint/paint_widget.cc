#include "paint_widget.h"
#include "./ui_widget.h"

namespace s21
{

PaintWidget::PaintWidget(QWidget *parent) :
        QWidget(parent) , ui_(new Ui::PaintWidget) {

    ui_->setupUi(this);
    ui_->paint_area->SetUi(ui_);

}

ImageWidget::ImageWidget(QWidget* parent) :
        QWidget(parent), image_(QSize(1, 1), QImage::Format_ARGB32),
        pen_(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin) {
    
    image_.fill(Qt::white);

}

void ImageWidget::SetUi(Ui::PaintWidget* ui) {
    ui_ = ui;

    connect(ui_->brush_button, &QPushButton::clicked, this, [&]() {
        pen_.setColor(Qt::black);
    });
    connect(ui_->erase_button, &QPushButton::clicked, this, [&]() {
        pen_.setColor(Qt::white);
    });
    connect(ui_->size_slider, &QSlider::valueChanged, this, [&](int value) {
        pen_.setWidth(value);
    });
    connect(ui_->opacity_slider, &QSlider::valueChanged, this, [&](int value) {
        auto c = pen_.color();
        c.setAlpha(value);
        pen_.setColor(c);
    });

    connect(ui_->clear_button, &QPushButton::clicked, this, [&]() {
        image_.fill(Qt::white);
        update();
    });

    connect(ui_->load_button, &QPushButton::clicked, this, [&]() {
        QString file_path = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("BMP Files (*.bmp);;All Files (*)"));

        if (file_path.isEmpty() || !image_.load(file_path)) {
            QMessageBox::critical(this, tr("Error"), tr("Failed to load image!"));
        } else {
            update();
        }
    });

    connect(ui_->save_button, &QPushButton::clicked, this, [&]() {
        QString file_path = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("BMP Files (*.bmp)"));

        if (file_path.isEmpty() || ! image_.save(file_path + ".bmp", "BMP")) {
            QMessageBox::critical(this, tr("Error"), tr("Failed to save image!"));
        }
    });

    // connect(ui_->predict_button, &QPushButton::clicked, [&]() {
    //     auto image = image_.scaled(28, 28, Qt::KeepAspectRatio);
    //     std::vector<fp_type> input;
    //     for (int i = 0; i < image.height(); ++i) {
    //         for (int j = 0; j < image.width(); ++j) {
    //             input.push_back(1 - qGray(image.pixel(j, i)) / 255.0);
    //         }
    //     }

    //     // TEST
    //     auto output = mm.Predict(input);

    //     // DEBUG
    //     DataManager::PrintLetter(input);

    //     // TEST
    //     ui_->predict_label->setText(QString((char)('a' + output)));
    // });

    SetPen();
}

void ImageWidget::resizeEvent(QResizeEvent *event) {
    
    QWidget::resizeEvent(event);
    image_ = image_.scaled(event->size(), Qt::KeepAspectRatio);
}

void ImageWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.drawImage(0, 0, image_);
}

void ImageWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing_ = true;
        prev_image_ = image_;
        path_.moveTo(event->pos());

    }
}

void ImageWidget::Draw() {
    if (path_.length() != 0) {
        image_ = prev_image_;
    }
    painter_.begin(&image_);
    painter_.setPen(pen_);
    if (path_.length() == 0) {
        painter_.drawPoint(path_.currentPosition());
    } else {
        painter_.drawPath(path_);
    }
    painter_.end();

    update();
}

void ImageWidget::SetPen() {
    QColor color = ui_->brush_button->isChecked() ? Qt::black : Qt::white;
    color.setAlpha(ui_->opacity_slider->value());
    int radius = ui_->size_slider->value();

    pen_.setColor(color);
    
    pen_.setWidth(radius);
}


void ImageWidget::mouseMoveEvent(QMouseEvent *event) {
    if (drawing_ && rect().contains(event->pos())) {
        path_.lineTo(event->pos());

        Draw();
    }

}

void ImageWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && drawing_) {
        drawing_ = false;

        Draw();

        path_.clear();
    }
}


PaintWidget::~PaintWidget() {
    delete ui_;
}

} // namespace s21
