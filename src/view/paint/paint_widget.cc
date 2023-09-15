#include "paint_widget.h"
#include "./ui_widget.h"

namespace s21
{

PaintWidget::PaintWidget(QWidget *parent) 
    : QWidget(parent)
    , ui_(new Ui::PaintWidget) 
{
    ui_->setupUi(this);

    connect(ui_->brush_button, &QPushButton::clicked, this, [&]()
    {
        ui_->paint_area->GetPen().setColor(Qt::black);
    });
    connect(ui_->erase_button, &QPushButton::clicked, this, [&]()
    {
        ui_->paint_area->GetPen().setColor(Qt::white);
    });
    connect(ui_->size_slider, &QSlider::valueChanged, this, [&](int value)
    {
        ui_->paint_area->GetPen().setWidth(value);
    });
    connect(ui_->opacity_slider, &QSlider::valueChanged, this, [&](int value)
    {
        QColor color = ui_->paint_area->GetPen().color();
        color.setAlpha(value);
        ui_->paint_area->GetPen().setColor(color);
    });
    connect(ui_->clear_button, &QPushButton::clicked, this, [&]()
    {
        ui_->paint_area->Clear();
    });
    connect(ui_->load_button, &QPushButton::clicked, this, [&]()
    {
        QString file_path = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("BMP Files (*.bmp);;All Files (*)"));

        if (!file_path.isEmpty())
        {
            ui_->paint_area->LoadImage(file_path);
        }
    });
    connect(ui_->save_button, &QPushButton::clicked, this, [&]()
    {
        QString file_path = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("BMP Files (*.bmp)"));

        if (!file_path.isEmpty())
        {
            ui_->paint_area->SaveImage(file_path);
        }
    });
    connect(ui_->predict_button, &QPushButton::clicked, this, [&]()
    {
        emit SendImage(ui_->paint_area->GetImage());
    });
    ui_->size_slider->setValue(99);
}

PaintWidget::~PaintWidget() 
{
    delete ui_;
}

void PaintWidget::SetPredict(char c)
{
    ui_->predict_label->setText(QString(c));
}

ImageWidget::ImageWidget(QWidget* parent) 
    : QWidget(parent)
    , image_(QSize(1, 1), QImage::Format_ARGB32)
    , pen_(Qt::black, 12, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)
{
    Clear();
}

QPen& ImageWidget::GetPen()
{
    return pen_;
}

void ImageWidget::Clear()
{
    image_.fill(Qt::white);
    update();
}

void ImageWidget::LoadImage(QString file_path)
{
    if (image_.load(file_path))
    {
        update();
    }
}

void ImageWidget::SaveImage(QString file_path)
{
    image_.save(file_path + ".bmp", "BMP");
}

std::vector<fp_type> ImageWidget::GetImage()
{
    QImage image = image_.scaled(28, 28, Qt::KeepAspectRatio);
    std::vector<fp_type> input;

    for (int i = 0; i < image.height(); ++i)
    {
        for (int j = 0; j < image.width(); ++j)
        {
            input.push_back(1 - qGray(image.pixel(j, i)) / 255.0);
        }
    }

    return input;
}

void ImageWidget::Draw()
{
    if (path_.length() != 0)
    {
        image_ = prev_image_;
    }
    painter_.begin(&image_);
    painter_.setPen(pen_);
    if (path_.length() == 0)
    {
        painter_.drawPoint(path_.currentPosition());
    }
    else
    {
        painter_.drawPath(path_);
    }
    painter_.end();

    update();
}

void ImageWidget::resizeEvent(QResizeEvent *event) 
{
    image_ = image_.scaled(event->size(), Qt::KeepAspectRatio);
    QWidget::resizeEvent(event);
}

void ImageWidget::paintEvent(QPaintEvent *event) 
{
    QPainter(this).drawImage(0, 0, image_);
    QWidget::paintEvent(event);
}

void ImageWidget::mousePressEvent(QMouseEvent *event) 
{
    if (event->button() == Qt::LeftButton) 
    {
        drawing_ = true;
        prev_image_ = image_;
        path_.moveTo(event->pos());
    }
}

void ImageWidget::mouseMoveEvent(QMouseEvent *event) 
{
    if (drawing_ && rect().contains(event->pos())) 
    {
        path_.lineTo(event->pos());
        Draw();
    }
}

void ImageWidget::mouseReleaseEvent(QMouseEvent *event) 
{
    if (event->button() == Qt::LeftButton && drawing_) 
    {
        drawing_ = false;
        Draw();
        path_.clear();
    }
}

} // namespace s21
