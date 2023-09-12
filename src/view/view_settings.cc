#include "mainwindow.h"

namespace s21
{

struct ConfigConstants
{
    static constexpr const char* kModelType = "modelType";
    static constexpr const char* kLearningType = "learningType";
    static constexpr const char* kLearningRate = "learningRate";
    static constexpr const char* kNumberOfEpochs = "numberOfEpochs";
    static constexpr const char* kNumberOfGroups = "numberOfGroups";
    static constexpr const char* kActivationFunction = "activationFunctionType";
    static constexpr const char* kWeightFunction = "weightFunctionType";
    static constexpr const char* kMomentum = "momentum";
    static constexpr const char* kLRReductionRatioByEpoch = "reductionRatioByEpoch";
    static constexpr const char* kLRReductionRatioByLayer = "reductionRatioByLayer";
    static constexpr const char* kDatasetTrainingPath = "trainingPath";
    static constexpr const char* kDatasetTestsPath = "testsPath";
};

void MainWindow::SaveViewSettings_()
{
    view_settings_->setValue(ConfigConstants::kModelType, ui_->modelType->currentIndex());
    view_settings_->setValue(ConfigConstants::kLearningType, ui_->learningType->currentIndex());
    view_settings_->setValue(ConfigConstants::kLearningRate, ui_->learningRate->text());
    view_settings_->setValue(ConfigConstants::kNumberOfEpochs, ui_->numberOfEpochs->text());
    view_settings_->setValue(ConfigConstants::kNumberOfGroups, ui_->numberOfGroups->text());
    view_settings_->setValue(ConfigConstants::kActivationFunction, ui_->activationFunction->currentIndex());
    view_settings_->setValue(ConfigConstants::kWeightFunction, ui_->weightFunction->currentIndex());
    view_settings_->setValue(ConfigConstants::kMomentum, ui_->momentum->text());
    view_settings_->setValue(ConfigConstants::kLRReductionRatioByEpoch, ui_->learningRateEpochK->text());
    view_settings_->setValue(ConfigConstants::kLRReductionRatioByLayer, ui_->learningRateLayerK->text());
    view_settings_->setValue(ConfigConstants::kDatasetTrainingPath, ui_->datasetTrainingPath->text());
    view_settings_->setValue(ConfigConstants::kDatasetTestsPath, ui_->datasetTestsPath->text());
}

void MainWindow::RestoreViewSettings_()
{
    int model_type = view_settings_->value(ConfigConstants::kModelType, 0).toInt();
    int learning_type = view_settings_->value(ConfigConstants::kLearningType, 0).toInt();
    QString learning_rate = view_settings_->value(ConfigConstants::kLearningRate, 0.25).toString();
    QString number_of_epochs = view_settings_->value(ConfigConstants::kNumberOfEpochs, 1).toString();
    QString number_of_groups = view_settings_->value(ConfigConstants::kNumberOfGroups, 1).toString();
    int activation_function_type = view_settings_->value(ConfigConstants::kActivationFunction, 0).toInt();
    int weight_function_type = view_settings_->value(ConfigConstants::kWeightFunction, 0).toInt();
    QString momentum = view_settings_->value(ConfigConstants::kMomentum, 0.2).toString();
    QString reduction_ratio_by_epoch = view_settings_->value(ConfigConstants::kLRReductionRatioByEpoch, 1).toString();
    QString reduction_ratio_by_layer = view_settings_->value(ConfigConstants::kLRReductionRatioByLayer, 1).toString();
    QString training_path = view_settings_->value(ConfigConstants::kDatasetTrainingPath, "").toString();
    QString tests_path = view_settings_->value(ConfigConstants::kDatasetTestsPath, "").toString();

    ui_->modelType->setCurrentIndex(model_type);
    ui_->learningType->setCurrentIndex(learning_type);
    ui_->learningRate->setText(learning_rate);
    ui_->numberOfEpochs->setText(number_of_epochs);
    ui_->numberOfGroups->setText(number_of_groups);
    ui_->activationFunction->setCurrentIndex(activation_function_type);
    ui_->weightFunction->setCurrentIndex(weight_function_type);
    ui_->momentum->setText(momentum);
    ui_->learningRateEpochK->setText(reduction_ratio_by_epoch);
    ui_->learningRateLayerK->setText(reduction_ratio_by_layer);
    ui_->datasetTrainingPath->setText(training_path);
    ui_->datasetTestsPath->setText(tests_path);
}

} // namespace s21
