#ifndef CPP7_MLP_VIEW_CONSTANTS_H_
#define CPP7_MLP_VIEW_CONSTANTS_H_

namespace s21
{

struct ConfigConstants
{
    static constexpr const char* kModelType = "modelType";
    static constexpr const char* kLearningRate = "learningRate";
    static constexpr const char* kNumberOfEpochs = "numberOfEpochs";
    static constexpr const char* kNumberOfGroups = "numberOfGroups";
    static constexpr const char* kTestProportion = "testProportion";
    static constexpr const char* kActivationFunction = "activationFunctionType";
    static constexpr const char* kWeightFunction = "weightFunctionType";
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
