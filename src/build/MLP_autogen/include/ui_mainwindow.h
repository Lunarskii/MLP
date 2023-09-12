/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSaveAs;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionOpenADatasetForTraining;
    QAction *actionOpenADatasetForTests;
    QAction *actionOpenAMappingFile;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *applicationTabWidget;
    QWidget *mainTab;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QWidget *informationWIdget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *labelAccuracy;
    QLabel *labelPrecision;
    QLabel *labelRecall;
    QLabel *labelFMeasure;
    QLabel *labelTotalTime;
    QSpacerItem *horizontalSpacer_5;
    QWidget *mainWidget;
    QLabel *labelModelSelection;
    QLabel *labelLayers;
    QPushButton *openGraphTabButton;
    QPushButton *openPaintTabButton;
    QPushButton *startTrainingButton;
    QPushButton *openApplicationSettingsTabButton;
    QLabel *labelLearningRateMain;
    QComboBox *modelType;
    QListWidget *layersListWidget;
    QComboBox *learningType;
    QLabel *labelLearningTypeSelection;
    QTabWidget *learningTypeWidget;
    QWidget *standardType;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelNumberOfEpochs;
    QSpacerItem *horizontalSpacer;
    QLineEdit *numberOfEpochs;
    QWidget *crossValidationType;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelNumberOfGroups;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *numberOfGroups;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addLayerButton;
    QPushButton *removeLayerButton;
    QLineEdit *learningRate;
    QPushButton *setModelButton;
    QPushButton *startTestButton;
    QTabWidget *tabDisplayWidget;
    QWidget *graphWidget;
    QWidget *paintWidget;
    QWidget *settingsTab;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QWidget *datasetDirectoriesWidget;
    QLabel *labelDatasetDirectories;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_4;
    QLineEdit *datasetTrainingPath;
    QPushButton *browseDatasetForTraining;
    QLineEdit *datasetTestsPath;
    QPushButton *browseDatasetForTesting;
    QWidget *momentumWidget;
    QLabel *labelMomentum;
    QLineEdit *momentum;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *descriptionMomentum;
    QPushButton *exitApplicationSettingsTabButton;
    QSpacerItem *horizontalSpacer_4;
    QWidget *learningRateWidget;
    QLabel *labelLearningRate;
    QLineEdit *learningRateEpochK;
    QLineEdit *learningRateLayerK;
    QLabel *labelLearningRateEpochs;
    QLabel *labelLearningRateLayers;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *descriptionLearningRate;
    QWidget *weightWidget;
    QLabel *labelWeight;
    QComboBox *weightFunction;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *descriptionWeight;
    QSpacerItem *verticalSpacer_2;
    QWidget *activationWidget;
    QLabel *labelActivationFunction;
    QComboBox *activationFunction;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *descriptionActivationFunction;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuOpen_file;
    QStatusBar *statusbar;
    QButtonGroup *widgetDisplayButtonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 770);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: #474953;\n"
"}"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpenADatasetForTraining = new QAction(MainWindow);
        actionOpenADatasetForTraining->setObjectName(QString::fromUtf8("actionOpenADatasetForTraining"));
        actionOpenADatasetForTests = new QAction(MainWindow);
        actionOpenADatasetForTests->setObjectName(QString::fromUtf8("actionOpenADatasetForTests"));
        actionOpenAMappingFile = new QAction(MainWindow);
        actionOpenAMappingFile->setObjectName(QString::fromUtf8("actionOpenAMappingFile"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        applicationTabWidget = new QTabWidget(centralwidget);
        applicationTabWidget->setObjectName(QString::fromUtf8("applicationTabWidget"));
        applicationTabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        applicationTabWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: #1E1E1E;\n"
"}\n"
""));
        applicationTabWidget->setTabShape(QTabWidget::Rounded);
        applicationTabWidget->setIconSize(QSize(16, 16));
        applicationTabWidget->setElideMode(Qt::ElideNone);
        applicationTabWidget->setUsesScrollButtons(true);
        applicationTabWidget->setTabBarAutoHide(false);
        mainTab = new QWidget();
        mainTab->setObjectName(QString::fromUtf8("mainTab"));
        gridLayout_3 = new QGridLayout(mainTab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer, 2, 2, 1, 1);

        informationWIdget = new QWidget(mainTab);
        informationWIdget->setObjectName(QString::fromUtf8("informationWIdget"));
        informationWIdget->setMinimumSize(QSize(150, 100));
        informationWIdget->setMaximumSize(QSize(200, 100));
        informationWIdget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border: 1px solid black;\n"
"}"));
        horizontalLayout = new QHBoxLayout(informationWIdget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelAccuracy = new QLabel(informationWIdget);
        labelAccuracy->setObjectName(QString::fromUtf8("labelAccuracy"));
        QFont font;
        font.setPointSize(9);
        labelAccuracy->setFont(font);
        labelAccuracy->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelAccuracy);

        labelPrecision = new QLabel(informationWIdget);
        labelPrecision->setObjectName(QString::fromUtf8("labelPrecision"));
        labelPrecision->setFont(font);
        labelPrecision->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPrecision);

        labelRecall = new QLabel(informationWIdget);
        labelRecall->setObjectName(QString::fromUtf8("labelRecall"));
        labelRecall->setFont(font);
        labelRecall->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"}"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelRecall);

        labelFMeasure = new QLabel(informationWIdget);
        labelFMeasure->setObjectName(QString::fromUtf8("labelFMeasure"));
        labelFMeasure->setFont(font);
        labelFMeasure->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"}"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelFMeasure);

        labelTotalTime = new QLabel(informationWIdget);
        labelTotalTime->setObjectName(QString::fromUtf8("labelTotalTime"));
        labelTotalTime->setFont(font);
        labelTotalTime->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"}"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelTotalTime);


        horizontalLayout->addLayout(formLayout);


        gridLayout_3->addWidget(informationWIdget, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        mainWidget = new QWidget(mainTab);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainWidget->sizePolicy().hasHeightForWidth());
        mainWidget->setSizePolicy(sizePolicy);
        mainWidget->setMinimumSize(QSize(250, 600));
        mainWidget->setMaximumSize(QSize(250, 16777215));
        mainWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border: 1px solid black;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #B4B4B4;\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"	background-color: #3C3C3C;\n"
"	color: #AAAAAA;\n"
"	border-radius: 4px;\n"
"	padding-left: 10px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:  #40424B;\n"
"	color: #B4B4B4;\n"
"	border: solid;\n"
"	border-radius: 6.5;\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	background-color: rgb(78, 80, 89);\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color:  #40424B;\n"
"}\n"
"\n"
"QSpinBox\n"
"{\n"
"	color: #B4B4B4;\n"
"	background-color: #40424B;\n"
"	border: 1px solid #393C46;\n"
"	border-radius: 4;\n"
"}\n"
"\n"
"QDoubleSpinBox\n"
"{\n"
"	color: #B4B4B4;\n"
"	background-color: #40424B;\n"
"	border: 1px solid #393C46;\n"
"	border-radius: 4;\n"
"}\n"
"\n"
"QComboBox \n"
"{\n"
"	background-color: #3C3C3C;\n"
"	color: #AAAAAA;\n"
"	border-radius: 4px;\n"
"	padding-left: 10px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QComboBox::dr"
                        "op-down\n"
"{\n"
"	border: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	image: url(:/resources/images/Icons8_flat_expand.svg.png);\n"
"	width: 12px;\n"
"	height: 12px;\n"
"	margin-right: 15px;\n"
"}\n"
"\n"
"QComboBox::hover\n"
"{\n"
"	border: 0.5px solid #CED4DA;\n"
"}"));
        labelModelSelection = new QLabel(mainWidget);
        labelModelSelection->setObjectName(QString::fromUtf8("labelModelSelection"));
        labelModelSelection->setGeometry(QRect(20, 20, 61, 20));
        labelModelSelection->setStyleSheet(QString::fromUtf8(""));
        labelLayers = new QLabel(mainWidget);
        labelLayers->setObjectName(QString::fromUtf8("labelLayers"));
        labelLayers->setGeometry(QRect(90, 320, 51, 17));
        labelLayers->setStyleSheet(QString::fromUtf8(""));
        openGraphTabButton = new QPushButton(mainWidget);
        widgetDisplayButtonGroup = new QButtonGroup(MainWindow);
        widgetDisplayButtonGroup->setObjectName(QString::fromUtf8("widgetDisplayButtonGroup"));
        widgetDisplayButtonGroup->addButton(openGraphTabButton);
        openGraphTabButton->setObjectName(QString::fromUtf8("openGraphTabButton"));
        openGraphTabButton->setGeometry(QRect(20, 594, 101, 31));
        openGraphTabButton->setStyleSheet(QString::fromUtf8(""));
        openPaintTabButton = new QPushButton(mainWidget);
        widgetDisplayButtonGroup->addButton(openPaintTabButton);
        openPaintTabButton->setObjectName(QString::fromUtf8("openPaintTabButton"));
        openPaintTabButton->setGeometry(QRect(138, 594, 101, 31));
        openPaintTabButton->setStyleSheet(QString::fromUtf8(""));
        startTrainingButton = new QPushButton(mainWidget);
        startTrainingButton->setObjectName(QString::fromUtf8("startTrainingButton"));
        startTrainingButton->setGeometry(QRect(40, 440, 181, 31));
        startTrainingButton->setStyleSheet(QString::fromUtf8(""));
        openApplicationSettingsTabButton = new QPushButton(mainWidget);
        openApplicationSettingsTabButton->setObjectName(QString::fromUtf8("openApplicationSettingsTabButton"));
        openApplicationSettingsTabButton->setGeometry(QRect(80, 530, 101, 31));
        openApplicationSettingsTabButton->setStyleSheet(QString::fromUtf8(""));
        labelLearningRateMain = new QLabel(mainWidget);
        labelLearningRateMain->setObjectName(QString::fromUtf8("labelLearningRateMain"));
        labelLearningRateMain->setGeometry(QRect(10, 80, 121, 17));
        labelLearningRateMain->setStyleSheet(QString::fromUtf8(""));
        modelType = new QComboBox(mainWidget);
        modelType->addItem(QString());
        modelType->addItem(QString());
        modelType->setObjectName(QString::fromUtf8("modelType"));
        modelType->setGeometry(QRect(120, 20, 121, 25));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        modelType->setFont(font1);
        modelType->setStyleSheet(QString::fromUtf8(""));
        layersListWidget = new QListWidget(mainWidget);
        QFont font2;
        font2.setKerning(true);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(layersListWidget);
        __qlistwidgetitem->setFont(font2);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(layersListWidget);
        __qlistwidgetitem1->setBackground(brush1);
        __qlistwidgetitem1->setForeground(brush);
        __qlistwidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(layersListWidget);
        __qlistwidgetitem2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        new QListWidgetItem(layersListWidget);
        layersListWidget->setObjectName(QString::fromUtf8("layersListWidget"));
        layersListWidget->setGeometry(QRect(20, 350, 170, 78));
        QPalette palette;
        QBrush brush2(QColor(30, 30, 30, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        layersListWidget->setPalette(palette);
        QFont font3;
        font3.setPointSize(11);
        layersListWidget->setFont(font3);
        layersListWidget->setStyleSheet(QString::fromUtf8("QListWidget::item\n"
"{\n"
"	border: 1px solid black;\n"
"	background-color:  #40424B;\n"
"	color: #B4B4B4;\n"
"}\n"
"\n"
"QListWidget::item::hover\n"
"{\n"
"	background-color: rgb(78, 80, 89);\n"
"	color: #B4B4B4;\n"
"}\n"
"\n"
"QListWidget::item::selected\n"
"{\n"
"	background-color: rgb(105, 107, 118);\n"
"	color: #B4B4B4;\n"
"}\n"
""));
        learningType = new QComboBox(mainWidget);
        learningType->addItem(QString());
        learningType->addItem(QString());
        learningType->setObjectName(QString::fromUtf8("learningType"));
        learningType->setGeometry(QRect(120, 50, 121, 25));
        learningType->setFont(font1);
        learningType->setStyleSheet(QString::fromUtf8(""));
        labelLearningTypeSelection = new QLabel(mainWidget);
        labelLearningTypeSelection->setObjectName(QString::fromUtf8("labelLearningTypeSelection"));
        labelLearningTypeSelection->setGeometry(QRect(10, 50, 101, 20));
        labelLearningTypeSelection->setStyleSheet(QString::fromUtf8(""));
        learningTypeWidget = new QTabWidget(mainWidget);
        learningTypeWidget->setObjectName(QString::fromUtf8("learningTypeWidget"));
        learningTypeWidget->setGeometry(QRect(20, 130, 201, 91));
        learningTypeWidget->setStyleSheet(QString::fromUtf8("border: 0px;"));
        learningTypeWidget->setInputMethodHints(Qt::ImhNone);
        learningTypeWidget->setTabBarAutoHide(false);
        standardType = new QWidget();
        standardType->setObjectName(QString::fromUtf8("standardType"));
        horizontalLayout_6 = new QHBoxLayout(standardType);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelNumberOfEpochs = new QLabel(standardType);
        labelNumberOfEpochs->setObjectName(QString::fromUtf8("labelNumberOfEpochs"));
        labelNumberOfEpochs->setMinimumSize(QSize(125, 0));
        labelNumberOfEpochs->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_6->addWidget(labelNumberOfEpochs);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        numberOfEpochs = new QLineEdit(standardType);
        numberOfEpochs->setObjectName(QString::fromUtf8("numberOfEpochs"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(numberOfEpochs->sizePolicy().hasHeightForWidth());
        numberOfEpochs->setSizePolicy(sizePolicy1);
        numberOfEpochs->setMinimumSize(QSize(40, 20));
        numberOfEpochs->setMaximumSize(QSize(40, 20));
        numberOfEpochs->setFont(font1);

        horizontalLayout_6->addWidget(numberOfEpochs);

        learningTypeWidget->addTab(standardType, QString());
        crossValidationType = new QWidget();
        crossValidationType->setObjectName(QString::fromUtf8("crossValidationType"));
        horizontalLayout_7 = new QHBoxLayout(crossValidationType);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelNumberOfGroups = new QLabel(crossValidationType);
        labelNumberOfGroups->setObjectName(QString::fromUtf8("labelNumberOfGroups"));
        labelNumberOfGroups->setMinimumSize(QSize(125, 0));
        labelNumberOfGroups->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(labelNumberOfGroups);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        numberOfGroups = new QLineEdit(crossValidationType);
        numberOfGroups->setObjectName(QString::fromUtf8("numberOfGroups"));
        numberOfGroups->setMinimumSize(QSize(40, 20));
        numberOfGroups->setMaximumSize(QSize(40, 20));
        numberOfGroups->setFont(font1);

        horizontalLayout_7->addWidget(numberOfGroups);

        learningTypeWidget->addTab(crossValidationType, QString());
        layoutWidget = new QWidget(mainWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 350, 22, 48));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addLayerButton = new QPushButton(layoutWidget);
        addLayerButton->setObjectName(QString::fromUtf8("addLayerButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(addLayerButton->sizePolicy().hasHeightForWidth());
        addLayerButton->setSizePolicy(sizePolicy2);
        addLayerButton->setMinimumSize(QSize(20, 20));
        addLayerButton->setMaximumSize(QSize(30, 30));

        verticalLayout->addWidget(addLayerButton);

        removeLayerButton = new QPushButton(layoutWidget);
        removeLayerButton->setObjectName(QString::fromUtf8("removeLayerButton"));
        sizePolicy2.setHeightForWidth(removeLayerButton->sizePolicy().hasHeightForWidth());
        removeLayerButton->setSizePolicy(sizePolicy2);
        removeLayerButton->setMinimumSize(QSize(20, 20));
        removeLayerButton->setMaximumSize(QSize(30, 30));

        verticalLayout->addWidget(removeLayerButton);

        learningRate = new QLineEdit(mainWidget);
        learningRate->setObjectName(QString::fromUtf8("learningRate"));
        learningRate->setGeometry(QRect(130, 80, 100, 20));
        sizePolicy1.setHeightForWidth(learningRate->sizePolicy().hasHeightForWidth());
        learningRate->setSizePolicy(sizePolicy1);
        learningRate->setMinimumSize(QSize(40, 20));
        learningRate->setMaximumSize(QSize(100, 20));
        learningRate->setFont(font1);
        setModelButton = new QPushButton(mainWidget);
        setModelButton->setObjectName(QString::fromUtf8("setModelButton"));
        setModelButton->setGeometry(QRect(60, 250, 121, 31));
        setModelButton->setStyleSheet(QString::fromUtf8(""));
        startTestButton = new QPushButton(mainWidget);
        startTestButton->setObjectName(QString::fromUtf8("startTestButton"));
        startTestButton->setGeometry(QRect(40, 480, 181, 31));
        startTestButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(mainWidget, 0, 2, 2, 1);

        tabDisplayWidget = new QTabWidget(mainTab);
        tabDisplayWidget->setObjectName(QString::fromUtf8("tabDisplayWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabDisplayWidget->sizePolicy().hasHeightForWidth());
        tabDisplayWidget->setSizePolicy(sizePolicy3);
        tabDisplayWidget->setMinimumSize(QSize(500, 500));
        tabDisplayWidget->setMaximumSize(QSize(16777215, 16777215));
        tabDisplayWidget->setStyleSheet(QString::fromUtf8("background-color: #1E1E1E;"));
        graphWidget = new QWidget();
        graphWidget->setObjectName(QString::fromUtf8("graphWidget"));
        sizePolicy2.setHeightForWidth(graphWidget->sizePolicy().hasHeightForWidth());
        graphWidget->setSizePolicy(sizePolicy2);
        graphWidget->setMinimumSize(QSize(500, 525));
        tabDisplayWidget->addTab(graphWidget, QString());
        paintWidget = new QWidget();
        paintWidget->setObjectName(QString::fromUtf8("paintWidget"));
        tabDisplayWidget->addTab(paintWidget, QString());

        gridLayout_3->addWidget(tabDisplayWidget, 0, 0, 1, 1);

        applicationTabWidget->addTab(mainTab, QString());
        settingsTab = new QWidget();
        settingsTab->setObjectName(QString::fromUtf8("settingsTab"));
        settingsTab->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(settingsTab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(15, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 7, 1, 1, 1);

        datasetDirectoriesWidget = new QWidget(settingsTab);
        datasetDirectoriesWidget->setObjectName(QString::fromUtf8("datasetDirectoriesWidget"));
        datasetDirectoriesWidget->setMinimumSize(QSize(300, 100));
        datasetDirectoriesWidget->setMaximumSize(QSize(16777215, 120));
        datasetDirectoriesWidget->setStyleSheet(QString::fromUtf8("QWidget::hover\n"
"{\n"
"	border: 0.5px solid #6495ED;\n"
"}"));
        labelDatasetDirectories = new QLabel(datasetDirectoriesWidget);
        labelDatasetDirectories->setObjectName(QString::fromUtf8("labelDatasetDirectories"));
        labelDatasetDirectories->setGeometry(QRect(10, 10, 221, 21));
        labelDatasetDirectories->setFont(font1);
        labelDatasetDirectories->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"	font-weight: bold;\n"
"}"));
        gridLayoutWidget = new QWidget(datasetDirectoriesWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 40, 501, 61));
        gridLayout_4 = new QGridLayout(gridLayoutWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(0);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        datasetTrainingPath = new QLineEdit(gridLayoutWidget);
        datasetTrainingPath->setObjectName(QString::fromUtf8("datasetTrainingPath"));
        datasetTrainingPath->setEnabled(true);
        datasetTrainingPath->setMinimumSize(QSize(300, 20));
        datasetTrainingPath->setFont(font1);
        datasetTrainingPath->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: #3C3C3C;\n"
"	color: #AAAAAA;\n"
"	border-radius: 4px;\n"
"	padding-left: 10px;\n"
"	font-weight: bold;\n"
"	margin-right: 5px;\n"
"}"));
        datasetTrainingPath->setFrame(true);
        datasetTrainingPath->setEchoMode(QLineEdit::Normal);
        datasetTrainingPath->setCursorPosition(0);
        datasetTrainingPath->setAlignment(Qt::AlignCenter);
        datasetTrainingPath->setReadOnly(false);
        datasetTrainingPath->setCursorMoveStyle(Qt::LogicalMoveStyle);
        datasetTrainingPath->setClearButtonEnabled(false);

        gridLayout_4->addWidget(datasetTrainingPath, 0, 1, 1, 1);

        browseDatasetForTraining = new QPushButton(gridLayoutWidget);
        browseDatasetForTraining->setObjectName(QString::fromUtf8("browseDatasetForTraining"));
        browseDatasetForTraining->setMinimumSize(QSize(80, 20));
        browseDatasetForTraining->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:  #40424B;\n"
"	color: #B4B4B4;\n"
"	border: solid;\n"
"	border-radius: 6.5;\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	background-color: rgb(78, 80, 89);\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color:  #40424B;\n"
"}"));

        gridLayout_4->addWidget(browseDatasetForTraining, 0, 0, 1, 1);

        datasetTestsPath = new QLineEdit(gridLayoutWidget);
        datasetTestsPath->setObjectName(QString::fromUtf8("datasetTestsPath"));
        datasetTestsPath->setEnabled(false);
        datasetTestsPath->setMinimumSize(QSize(300, 20));
        datasetTestsPath->setFont(font1);
        datasetTestsPath->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: #3C3C3C;\n"
"	color: #AAAAAA;\n"
"	border-radius: 4px;\n"
"	padding-left: 10px;\n"
"	font-weight: bold;\n"
"	margin-right: 5px;\n"
"}"));
        datasetTestsPath->setFrame(true);
        datasetTestsPath->setEchoMode(QLineEdit::Normal);
        datasetTestsPath->setCursorPosition(0);
        datasetTestsPath->setAlignment(Qt::AlignCenter);
        datasetTestsPath->setReadOnly(true);
        datasetTestsPath->setClearButtonEnabled(false);

        gridLayout_4->addWidget(datasetTestsPath, 1, 1, 1, 1);

        browseDatasetForTesting = new QPushButton(gridLayoutWidget);
        browseDatasetForTesting->setObjectName(QString::fromUtf8("browseDatasetForTesting"));
        browseDatasetForTesting->setMinimumSize(QSize(80, 20));
        browseDatasetForTesting->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:  #40424B;\n"
"	color: #B4B4B4;\n"
"	border: solid;\n"
"	border-radius: 6.5;\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	background-color: rgb(78, 80, 89);\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color:  #40424B;\n"
"}"));

        gridLayout_4->addWidget(browseDatasetForTesting, 1, 0, 1, 1);


        gridLayout->addWidget(datasetDirectoriesWidget, 6, 0, 1, 2);

        momentumWidget = new QWidget(settingsTab);
        momentumWidget->setObjectName(QString::fromUtf8("momentumWidget"));
        momentumWidget->setMinimumSize(QSize(300, 100));
        momentumWidget->setMaximumSize(QSize(16777215, 120));
        momentumWidget->setStyleSheet(QString::fromUtf8("QWidget::hover\n"
"{\n"
"	border: 0.5px solid #6495ED;\n"
"}"));
        labelMomentum = new QLabel(momentumWidget);
        labelMomentum->setObjectName(QString::fromUtf8("labelMomentum"));
        labelMomentum->setGeometry(QRect(10, 10, 221, 21));
        labelMomentum->setFont(font1);
        labelMomentum->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"	font-weight: bold;\n"
"}"));
        momentum = new QLineEdit(momentumWidget);
        momentum->setObjectName(QString::fromUtf8("momentum"));
        momentum->setGeometry(QRect(30, 60, 201, 21));
        momentum->setFont(font1);
        momentum->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: #3C3C3C;\n"
"	color: #AAAAAA;\n"
"	border-radius: 4px;\n"
"	padding-left: 10px;\n"
"	font-weight: bold;\n"
"}"));
        momentum->setFrame(true);
        momentum->setEchoMode(QLineEdit::Normal);
        momentum->setClearButtonEnabled(false);
        horizontalLayoutWidget_3 = new QWidget(momentumWidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(30, 30, 471, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        descriptionMomentum = new QLabel(horizontalLayoutWidget_3);
        descriptionMomentum->setObjectName(QString::fromUtf8("descriptionMomentum"));
        descriptionMomentum->setFont(font);
        descriptionMomentum->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"}"));

        horizontalLayout_4->addWidget(descriptionMomentum);


        gridLayout->addWidget(momentumWidget, 4, 0, 1, 2);

        exitApplicationSettingsTabButton = new QPushButton(settingsTab);
        exitApplicationSettingsTabButton->setObjectName(QString::fromUtf8("exitApplicationSettingsTabButton"));
        exitApplicationSettingsTabButton->setMinimumSize(QSize(190, 25));
        exitApplicationSettingsTabButton->setMaximumSize(QSize(190, 25));
        exitApplicationSettingsTabButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:  #40424B;\n"
"	color: #B4B4B4;\n"
"	border: solid;\n"
"	border-radius: 6.5;\n"
"}"));

        gridLayout->addWidget(exitApplicationSettingsTabButton, 7, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 7, 4, 1, 1);

        learningRateWidget = new QWidget(settingsTab);
        learningRateWidget->setObjectName(QString::fromUtf8("learningRateWidget"));
        learningRateWidget->setMinimumSize(QSize(300, 120));
        learningRateWidget->setMaximumSize(QSize(16777215, 140));
        learningRateWidget->setStyleSheet(QString::fromUtf8("QWidget::hover\n"
"{\n"
"	border: 0.5px solid #6495ED;\n"
"}"));
        labelLearningRate = new QLabel(learningRateWidget);
        labelLearningRate->setObjectName(QString::fromUtf8("labelLearningRate"));
        labelLearningRate->setGeometry(QRect(10, 10, 221, 21));
        labelLearningRate->setFont(font1);
        labelLearningRate->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"	font-weight: bold;\n"
"}"));
        learningRateEpochK = new QLineEdit(learningRateWidget);
        learningRateEpochK->setObjectName(QString::fromUtf8("learningRateEpochK"));
        learningRateEpochK->setGeometry(QRect(90, 60, 201, 21));
        learningRateEpochK->setFont(font1);
        learningRateEpochK->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: #3C3C3C;\n"
"	color: #AAAAAA;\n"
"	border-radius: 4px;\n"
"	padding-left: 10px;\n"
"	font-weight: bold;\n"
"}"));
        learningRateLayerK = new QLineEdit(learningRateWidget);
        learningRateLayerK->setObjectName(QString::fromUtf8("learningRateLayerK"));
        learningRateLayerK->setGeometry(QRect(90, 90, 201, 21));
        learningRateLayerK->setFont(font1);
        learningRateLayerK->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: #3C3C3C;\n"
"	color: #AAAAAA;\n"
"	border-radius: 4px;\n"
"	padding-left: 10px;\n"
"	font-weight: bold;\n"
"}"));
        labelLearningRateEpochs = new QLabel(learningRateWidget);
        labelLearningRateEpochs->setObjectName(QString::fromUtf8("labelLearningRateEpochs"));
        labelLearningRateEpochs->setGeometry(QRect(30, 60, 51, 21));
        labelLearningRateEpochs->setFont(font1);
        labelLearningRateEpochs->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"	font-weight: bold;\n"
"}"));
        labelLearningRateLayers = new QLabel(learningRateWidget);
        labelLearningRateLayers->setObjectName(QString::fromUtf8("labelLearningRateLayers"));
        labelLearningRateLayers->setGeometry(QRect(30, 90, 51, 21));
        labelLearningRateLayers->setFont(font1);
        labelLearningRateLayers->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"	font-weight: bold;\n"
"}"));
        horizontalLayoutWidget_4 = new QWidget(learningRateWidget);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(30, 30, 471, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        descriptionLearningRate = new QLabel(horizontalLayoutWidget_4);
        descriptionLearningRate->setObjectName(QString::fromUtf8("descriptionLearningRate"));
        descriptionLearningRate->setFont(font);
        descriptionLearningRate->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"}"));

        horizontalLayout_5->addWidget(descriptionLearningRate);


        gridLayout->addWidget(learningRateWidget, 5, 0, 1, 2);

        weightWidget = new QWidget(settingsTab);
        weightWidget->setObjectName(QString::fromUtf8("weightWidget"));
        weightWidget->setMinimumSize(QSize(300, 100));
        weightWidget->setMaximumSize(QSize(16777215, 120));
        weightWidget->setStyleSheet(QString::fromUtf8("QWidget::hover\n"
"{\n"
"	border: 0.5px solid #6495ED;\n"
"}"));
        labelWeight = new QLabel(weightWidget);
        labelWeight->setObjectName(QString::fromUtf8("labelWeight"));
        labelWeight->setGeometry(QRect(10, 10, 221, 21));
        labelWeight->setFont(font1);
        labelWeight->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"	font-weight: bold;\n"
"}"));
        weightFunction = new QComboBox(weightWidget);
        weightFunction->addItem(QString());
        weightFunction->addItem(QString());
        weightFunction->setObjectName(QString::fromUtf8("weightFunction"));
        weightFunction->setGeometry(QRect(30, 60, 180, 25));
        weightFunction->setFont(font1);
        weightFunction->setStyleSheet(QString::fromUtf8("QComboBox \n"
"{\n"
"	background-color: #3C3C3C;\n"
"	color: #AAAAAA;\n"
"	border-radius: 4px;\n"
"	padding-left: 10px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"	border: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	\n"
"	image: url(:/resources/images/Icons8_flat_expand.svg.png);\n"
"	width: 12px;\n"
"	height: 12px;\n"
"	margin-right: 15px;\n"
"}\n"
"\n"
"QComboBox::hover\n"
"{\n"
"	border: 0.5px solid #CED4DA;\n"
"}"));
        horizontalLayoutWidget_2 = new QWidget(weightWidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 30, 471, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        descriptionWeight = new QLabel(horizontalLayoutWidget_2);
        descriptionWeight->setObjectName(QString::fromUtf8("descriptionWeight"));
        descriptionWeight->setFont(font);
        descriptionWeight->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"}"));

        horizontalLayout_3->addWidget(descriptionWeight);


        gridLayout->addWidget(weightWidget, 3, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 8, 2, 1, 1);

        activationWidget = new QWidget(settingsTab);
        activationWidget->setObjectName(QString::fromUtf8("activationWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(activationWidget->sizePolicy().hasHeightForWidth());
        activationWidget->setSizePolicy(sizePolicy4);
        activationWidget->setMinimumSize(QSize(300, 100));
        activationWidget->setMaximumSize(QSize(16777215, 120));
        activationWidget->setStyleSheet(QString::fromUtf8("QWidget::hover\n"
"{\n"
"	border: 0.5px solid #6495ED;\n"
"}"));
        labelActivationFunction = new QLabel(activationWidget);
        labelActivationFunction->setObjectName(QString::fromUtf8("labelActivationFunction"));
        labelActivationFunction->setGeometry(QRect(10, 10, 221, 21));
        labelActivationFunction->setFont(font1);
        labelActivationFunction->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"	font-weight: bold;\n"
"}"));
        activationFunction = new QComboBox(activationWidget);
        activationFunction->addItem(QString());
        activationFunction->addItem(QString());
        activationFunction->addItem(QString());
        activationFunction->setObjectName(QString::fromUtf8("activationFunction"));
        activationFunction->setEnabled(true);
        activationFunction->setGeometry(QRect(30, 60, 190, 25));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(190);
        sizePolicy5.setVerticalStretch(25);
        sizePolicy5.setHeightForWidth(activationFunction->sizePolicy().hasHeightForWidth());
        activationFunction->setSizePolicy(sizePolicy5);
        activationFunction->setMinimumSize(QSize(190, 25));
        activationFunction->setMaximumSize(QSize(190, 25));
        activationFunction->setFont(font1);
        activationFunction->setStyleSheet(QString::fromUtf8("QComboBox \n"
"{\n"
"	background-color: #3C3C3C;\n"
"	color: #AAAAAA;\n"
"	border-radius: 4px;\n"
"	padding-left: 10px;\n"
"	font-weight: bold;\n"
"	width: 180px;\n"
"	height: 25px;\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"	border: 0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"	\n"
"	image: url(:/resources/images/Icons8_flat_expand.svg.png);\n"
"	width: 12px;\n"
"	height: 12px;\n"
"	margin-right: 15px;\n"
"}\n"
"\n"
"QComboBox::hover\n"
"{\n"
"	border: 0.5px solid #CED4DA;\n"
"}"));
        horizontalLayoutWidget = new QWidget(activationWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 30, 471, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        descriptionActivationFunction = new QLabel(horizontalLayoutWidget);
        descriptionActivationFunction->setObjectName(QString::fromUtf8("descriptionActivationFunction"));
        descriptionActivationFunction->setFont(font);
        descriptionActivationFunction->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border: 0px;\n"
"	color: #AAAAAA;\n"
"}"));

        horizontalLayout_2->addWidget(descriptionActivationFunction);


        gridLayout->addWidget(activationWidget, 2, 0, 1, 2);

        applicationTabWidget->addTab(settingsTab, QString());

        gridLayout_2->addWidget(applicationTabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOpen_file = new QMenu(menuFile);
        menuOpen_file->setObjectName(QString::fromUtf8("menuOpen_file"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(menuOpen_file->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuOpen_file->addAction(actionOpenADatasetForTraining);
        menuOpen_file->addAction(actionOpenADatasetForTests);
        menuOpen_file->addAction(actionOpenAMappingFile);

        retranslateUi(MainWindow);

        applicationTabWidget->setCurrentIndex(0);
        learningTypeWidget->setCurrentIndex(0);
        tabDisplayWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open...", nullptr));
        actionOpenADatasetForTraining->setText(QCoreApplication::translate("MainWindow", "dataset for training", nullptr));
        actionOpenADatasetForTests->setText(QCoreApplication::translate("MainWindow", "dataset for tests", nullptr));
        actionOpenAMappingFile->setText(QCoreApplication::translate("MainWindow", "mapping file", nullptr));
        labelAccuracy->setText(QCoreApplication::translate("MainWindow", "Accuracy", nullptr));
        labelPrecision->setText(QCoreApplication::translate("MainWindow", "Precision", nullptr));
        labelRecall->setText(QCoreApplication::translate("MainWindow", "Recall", nullptr));
        labelFMeasure->setText(QCoreApplication::translate("MainWindow", "F-measure", nullptr));
        labelTotalTime->setText(QCoreApplication::translate("MainWindow", "Total time", nullptr));
        labelModelSelection->setText(QCoreApplication::translate("MainWindow", "Model", nullptr));
        labelLayers->setText(QCoreApplication::translate("MainWindow", "Layers", nullptr));
        openGraphTabButton->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        openPaintTabButton->setText(QCoreApplication::translate("MainWindow", "Paint", nullptr));
        startTrainingButton->setText(QCoreApplication::translate("MainWindow", "Start training", nullptr));
        openApplicationSettingsTabButton->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        labelLearningRateMain->setText(QCoreApplication::translate("MainWindow", "Learning rate", nullptr));
        modelType->setItemText(0, QCoreApplication::translate("MainWindow", "Matrix", nullptr));
        modelType->setItemText(1, QCoreApplication::translate("MainWindow", "Graph", nullptr));


        const bool __sortingEnabled = layersListWidget->isSortingEnabled();
        layersListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = layersListWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "784", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = layersListWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "400", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = layersListWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "200", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = layersListWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "26", nullptr));
        layersListWidget->setSortingEnabled(__sortingEnabled);

        learningType->setItemText(0, QCoreApplication::translate("MainWindow", "Standard", nullptr));
        learningType->setItemText(1, QCoreApplication::translate("MainWindow", "With cross-validation", nullptr));

        labelLearningTypeSelection->setText(QCoreApplication::translate("MainWindow", "Learning type", nullptr));
        labelNumberOfEpochs->setText(QCoreApplication::translate("MainWindow", "Number of epochs", nullptr));
        learningTypeWidget->setTabText(learningTypeWidget->indexOf(standardType), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        labelNumberOfGroups->setText(QCoreApplication::translate("MainWindow", "Number of groups", nullptr));
        learningTypeWidget->setTabText(learningTypeWidget->indexOf(crossValidationType), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        addLayerButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        removeLayerButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        learningRate->setText(QCoreApplication::translate("MainWindow", "0.1", nullptr));
        setModelButton->setText(QCoreApplication::translate("MainWindow", "Set up model", nullptr));
        startTestButton->setText(QCoreApplication::translate("MainWindow", "Start test", nullptr));
        tabDisplayWidget->setTabText(tabDisplayWidget->indexOf(graphWidget), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabDisplayWidget->setTabText(tabDisplayWidget->indexOf(paintWidget), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        applicationTabWidget->setTabText(applicationTabWidget->indexOf(mainTab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        labelDatasetDirectories->setText(QCoreApplication::translate("MainWindow", "Dataset directories", nullptr));
        datasetTrainingPath->setInputMask(QString());
        datasetTrainingPath->setText(QString());
        datasetTrainingPath->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter the path to the dataset for training", nullptr));
        browseDatasetForTraining->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        datasetTestsPath->setText(QString());
        datasetTestsPath->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter the path to the dataset for testing", nullptr));
        browseDatasetForTesting->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        labelMomentum->setText(QCoreApplication::translate("MainWindow", "Momentum", nullptr));
        momentum->setText(QCoreApplication::translate("MainWindow", "0.2", nullptr));
        descriptionMomentum->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        exitApplicationSettingsTabButton->setText(QCoreApplication::translate("MainWindow", "Exit settings", nullptr));
        labelLearningRate->setText(QCoreApplication::translate("MainWindow", "Learning rate reduction ratio", nullptr));
        learningRateEpochK->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        learningRateLayerK->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        labelLearningRateEpochs->setText(QCoreApplication::translate("MainWindow", "Epochs", nullptr));
        labelLearningRateLayers->setText(QCoreApplication::translate("MainWindow", "Layers", nullptr));
        descriptionLearningRate->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        labelWeight->setText(QCoreApplication::translate("MainWindow", "Weight", nullptr));
        weightFunction->setItemText(0, QCoreApplication::translate("MainWindow", "Normal", nullptr));
        weightFunction->setItemText(1, QCoreApplication::translate("MainWindow", "Xavier", nullptr));

        descriptionWeight->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        labelActivationFunction->setText(QCoreApplication::translate("MainWindow", "Activation function", nullptr));
        activationFunction->setItemText(0, QCoreApplication::translate("MainWindow", "Sigmoid", nullptr));
        activationFunction->setItemText(1, QCoreApplication::translate("MainWindow", "SiLU", nullptr));
        activationFunction->setItemText(2, QCoreApplication::translate("MainWindow", "ReLU", nullptr));

        descriptionActivationFunction->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        applicationTabWidget->setTabText(applicationTabWidget->indexOf(settingsTab), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOpen_file->setTitle(QCoreApplication::translate("MainWindow", "Open...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
