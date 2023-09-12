/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "paint_widget.h"

QT_BEGIN_NAMESPACE

class Ui_PaintWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *brush_button;
    QPushButton *erase_button;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSlider *size_slider;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSlider *opacity_slider;
    QPushButton *clear_button;
    QPushButton *load_button;
    QPushButton *save_button;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *predict_button;
    QLabel *predict_label;
    QSpacerItem *verticalSpacer;
    s21::ImageWidget *paint_area;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *PaintWidget)
    {
        if (PaintWidget->objectName().isEmpty())
            PaintWidget->setObjectName(QString::fromUtf8("PaintWidget"));
        PaintWidget->resize(800, 600);
        PaintWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: #1E1E1E;\n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(PaintWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(12);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        brush_button = new QPushButton(PaintWidget);
        buttonGroup = new QButtonGroup(PaintWidget);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(brush_button);
        brush_button->setObjectName(QString::fromUtf8("brush_button"));
        brush_button->setStyleSheet(QString::fromUtf8(""));
        brush_button->setCheckable(true);
        brush_button->setChecked(false);

        horizontalLayout->addWidget(brush_button);

        erase_button = new QPushButton(PaintWidget);
        buttonGroup->addButton(erase_button);
        erase_button->setObjectName(QString::fromUtf8("erase_button"));
        erase_button->setStyleSheet(QString::fromUtf8(""));
        erase_button->setCheckable(true);

        horizontalLayout->addWidget(erase_button);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(PaintWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        size_slider = new QSlider(PaintWidget);
        size_slider->setObjectName(QString::fromUtf8("size_slider"));
        size_slider->setValue(30);
        size_slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(size_slider);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(PaintWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        opacity_slider = new QSlider(PaintWidget);
        opacity_slider->setObjectName(QString::fromUtf8("opacity_slider"));
        opacity_slider->setMaximum(255);
        opacity_slider->setValue(128);
        opacity_slider->setOrientation(Qt::Horizontal);
        opacity_slider->setInvertedAppearance(false);
        opacity_slider->setInvertedControls(false);

        verticalLayout_2->addWidget(opacity_slider);


        verticalLayout_4->addLayout(verticalLayout_2);

        clear_button = new QPushButton(PaintWidget);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));

        verticalLayout_4->addWidget(clear_button);

        load_button = new QPushButton(PaintWidget);
        load_button->setObjectName(QString::fromUtf8("load_button"));

        verticalLayout_4->addWidget(load_button);

        save_button = new QPushButton(PaintWidget);
        save_button->setObjectName(QString::fromUtf8("save_button"));

        verticalLayout_4->addWidget(save_button);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        predict_button = new QPushButton(PaintWidget);
        predict_button->setObjectName(QString::fromUtf8("predict_button"));

        horizontalLayout_4->addWidget(predict_button);

        predict_label = new QLabel(PaintWidget);
        predict_label->setObjectName(QString::fromUtf8("predict_label"));

        horizontalLayout_4->addWidget(predict_label);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_4);

        paint_area = new s21::ImageWidget(PaintWidget);
        paint_area->setObjectName(QString::fromUtf8("paint_area"));

        horizontalLayout_2->addWidget(paint_area);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 10);

        retranslateUi(PaintWidget);

        QMetaObject::connectSlotsByName(PaintWidget);
    } // setupUi

    void retranslateUi(QWidget *PaintWidget)
    {
        PaintWidget->setWindowTitle(QCoreApplication::translate("PaintWidget", "PaintWidget", nullptr));
        brush_button->setText(QCoreApplication::translate("PaintWidget", "Brush", nullptr));
        erase_button->setText(QCoreApplication::translate("PaintWidget", "Erase", nullptr));
        label->setText(QCoreApplication::translate("PaintWidget", "Brush size", nullptr));
        label_2->setText(QCoreApplication::translate("PaintWidget", "Opacity", nullptr));
        clear_button->setText(QCoreApplication::translate("PaintWidget", "Clear", nullptr));
        load_button->setText(QCoreApplication::translate("PaintWidget", "Load image", nullptr));
        save_button->setText(QCoreApplication::translate("PaintWidget", "Save image", nullptr));
        predict_button->setText(QCoreApplication::translate("PaintWidget", "Predict", nullptr));
        predict_label->setText(QString());
#if QT_CONFIG(whatsthis)
        paint_area->setWhatsThis(QCoreApplication::translate("PaintWidget", "s21::CustomGraphicsView", nullptr));
#endif // QT_CONFIG(whatsthis)
    } // retranslateUi

};

namespace Ui {
    class PaintWidget: public Ui_PaintWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
