#ifndef CPP7_MLP_VIEW_CONSTANTS_H_
#define CPP7_MLP_VIEW_CONSTANTS_H_

#include <QColor>

namespace s21
{

struct MetricsWidgetStyle
{
    inline static unsigned int indent = 35;
    inline static unsigned int axes_size = 3;
    inline static unsigned int axes_text_size = 10;
    inline static unsigned int metrics_text_size = 12;
    inline static QColor background_color = QColor(15, 15, 15);
    inline static QColor axes_color = QColor(184, 134, 11);
    inline static QColor accuracy_color = QColor(132, 169, 141);
    inline static QColor precision_color = QColor(174, 124, 124);
    inline static QColor recall_color = QColor(92, 108, 124);
    inline static QColor f1_color = QColor(149, 149, 149);
    inline static QColor axes_text_color = QColor(184, 134, 11);
    inline static double chart_size_coef = 0.5;
    inline static unsigned int grid_size = 1;
    inline static QColor grid_color = Qt::white;
    inline static unsigned int grid_number = 10;
    inline static unsigned int classes = 26;
};

struct ConfigConstants
{
    static constexpr const char* kModelType = "modelType";
    static constexpr const char* kLearningRate = "learningRate";
    static constexpr const char* kNumberOfEpochs = "numberOfEpochs";
    static constexpr const char* kNumberOfGroups = "numberOfGroups";
    static constexpr const char* kTestProportion = "testProportion";
    static constexpr const char* kActivationFunction = "activationFunctionType";
    static constexpr const char* kWeightFunction = "weightFunctionType";
    static constexpr const char* kMean = "meanWeight";
    static constexpr const char* kStandardDeviation = "weightStandardDeviation";
    static constexpr const char* kMomentum = "momentum";
    static constexpr const char* kLRDecayByEpoch = "reductionRatioByEpoch";
    static constexpr const char* kLRDecayByLayer = "reductionRatioByLayer";
    static constexpr const char* kDatasetTrainingPath = "trainingPath";
    static constexpr const char* kDatasetTestsPath = "testsPath";
};

struct GraphWidgetConstants
{
    static constexpr const double kLowerZoomRatio = 0.8;
    static constexpr const double kUpperZoomRatio = 1.2;
    static constexpr const int kPenWidth = 3;
    inline static QColor kPenColor = QColor(255, 0, 0);
};

struct MetricsConstants
{
    static constexpr const unsigned int kNumberOfLettersDisplayed = 2;
};

}

#endif // CPP7_MLP_VIEW_CONSTANTS_H_
