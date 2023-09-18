#include "animated_button.h"

#include <QEvent>
#include <QDebug>

namespace s21
{

AnimatedButton::AnimatedButton(QString image, QString background_color, QWidget *parent)
    : QPushButton(parent)
    , image_url_(image)
    , background_color_(background_color)
    , animation_(this, "radius")
{
    this->setFixedSize(QSize(50, 50));
    this->installEventFilter(this);

    QString css("QPushButton {");
    css.append("image: " + image_url_ + ";");
    css.append("background-color: " + background_color_ + ";");
    css.append("background-repeat: no-repeat;");
    css.append("background-position: center;");
    css.append("border: 1px solid grey;");
    css.append("border-radius: " + QString::number(current_radius_) + "px;}");
    setStyleSheet(css);
}

void AnimatedButton::SetRadius(const unsigned int& radius)
{
    QString css("QPushButton {");
    current_radius_ = radius;

    css.append("image: " + image_url_ + ";");
    css.append("background-color: " + background_color_ + ";");
    css.append("background-repeat: no-repeat;");
    css.append("background-position: center;");
    css.append("border: 1px solid grey;");
    css.append("border-radius: " + QString::number(radius) + "px;}");
    setStyleSheet(css);
}

const unsigned int& AnimatedButton::GetRadius() const
{
    return current_radius_;
}

bool AnimatedButton::eventFilter(QObject *obj, QEvent *e)
{
    if (e->type() == QEvent::HoverEnter)
    {
        StartHoverEnterAnimation();
    }

    if (e->type() == QEvent::HoverLeave)
    {
        StartHoverLeaveAnimation();
    }

    return false;
}

void AnimatedButton::StartHoverEnterAnimation()
{
    animation_.stop();
    animation_.setDuration(300);
    animation_.setStartValue(GetRadius());
    animation_.setEndValue(15);
    animation_.start();
}

void AnimatedButton::StartHoverLeaveAnimation()
{
    animation_.stop();
    animation_.setDuration(300);
    animation_.setStartValue(GetRadius());
    animation_.setEndValue(25);
    animation_.start();
}

} // namespace s21
