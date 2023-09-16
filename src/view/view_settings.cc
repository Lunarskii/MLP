#include "mainwindow.h"
#include "view_constants.h"

namespace s21
{

void MainWindow::SaveViewSettings_()
{
    view_settings_->setValue(ConfigConstants::kModelType, ui_->modelType->currentIndex());
    view_settings_->setValue(ConfigConstants::kLearningRate, ui_->learningRate->text());
    view_settings_->setValue(ConfigConstants::kNumberOfEpochs, ui_->numberOfEpochs->text());
    view_settings_->setValue(ConfigConstants::kNumberOfGroups, ui_->numberOfGroups->text());
    view_settings_->setValue(ConfigConstants::kTestProportion, ui_->datasetProportion->value());
    view_settings_->setValue(ConfigConstants::kActivationFunction, ui_->activationFunction->currentIndex());
    view_settings_->setValue(ConfigConstants::kWeightFunction, ui_->weightFunction->currentIndex());
    view_settings_->setValue(ConfigConstants::kMomentum, ui_->momentum->text());
    view_settings_->setValue(ConfigConstants::kLRDecayByEpoch, ui_->learningRateDecayByEpoch->text());
    view_settings_->setValue(ConfigConstants::kLRDecayByLayer, ui_->learningRateDecayByLayer->text());
    view_settings_->setValue(ConfigConstants::kDatasetTrainingPath, ui_->datasetTrainingPath->text());
    view_settings_->setValue(ConfigConstants::kDatasetTestsPath, ui_->datasetTestsPath->text());
}

void MainWindow::RestoreViewSettings_()
{
    int model_type = view_settings_->value(ConfigConstants::kModelType, 0).toInt();
    QString learning_rate = view_settings_->value(ConfigConstants::kLearningRate, 0.25).toString();
    QString number_of_epochs = view_settings_->value(ConfigConstants::kNumberOfEpochs, 1).toString();
    QString number_of_groups = view_settings_->value(ConfigConstants::kNumberOfGroups, 1).toString();
    int test_proportion = view_settings_->value(ConfigConstants::kTestProportion, 5).toInt();
    int activation_function_type = view_settings_->value(ConfigConstants::kActivationFunction, 0).toInt();
    int weight_function_type = view_settings_->value(ConfigConstants::kWeightFunction, 0).toInt();
    QString momentum = view_settings_->value(ConfigConstants::kMomentum, 0.2).toString();
    QString reduction_ratio_by_epoch = view_settings_->value(ConfigConstants::kLRDecayByEpoch, 1).toString();
    QString reduction_ratio_by_layer = view_settings_->value(ConfigConstants::kLRDecayByLayer, 1).toString();
    QString training_path = view_settings_->value(ConfigConstants::kDatasetTrainingPath, "").toString();
    QString tests_path = view_settings_->value(ConfigConstants::kDatasetTestsPath, "").toString();

    ui_->modelType->setCurrentIndex(model_type);
    ui_->learningRate->setText(learning_rate);
    ui_->numberOfEpochs->setText(number_of_epochs);
    ui_->numberOfGroups->setText(number_of_groups);
    ui_->datasetProportion->setValue(test_proportion);
    ui_->activationFunction->setCurrentIndex(activation_function_type);
    ui_->weightFunction->setCurrentIndex(weight_function_type);
    ui_->momentum->setText(momentum);
    ui_->learningRateDecayByEpoch->setText(reduction_ratio_by_epoch);
    ui_->learningRateDecayByLayer->setText(reduction_ratio_by_layer);
    ui_->datasetTrainingPath->setText(training_path);
    ui_->datasetTestsPath->setText(tests_path);
}

} // namespace s21
