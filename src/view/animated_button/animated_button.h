#ifndef ANIMATEDBUTTON_H
#define ANIMATEDBUTTON_H

#include <QPushButton>
#include <QColor>
#include <QPropertyAnimation>

class AnimatedButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(unsigned int radius READ GetRadius WRITE SetRadius)

public:
    explicit AnimatedButton(QString image, QString background_color, QWidget *parent = nullptr);
    void SetRadius(const unsigned int& radius);
    const unsigned int& GetRadius() const;

protected:
    bool eventFilter(QObject *obj, QEvent *e);

private:
    QString image_url_;
    QString background_color_;
    QString background_properties_;
    QString border_properties_;
    unsigned int current_radius_{ 25 };
    QPropertyAnimation animation_;

    void StartHoverEnterAnimation();
    void StartHoverLeaveAnimation();
};

#endif // ANIMATEDBUTTON_H
