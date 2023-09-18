#include "mainwindow.h"

namespace s21
{

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , graph_widget_(new GraphWidget("Epochs", "Error", this))
    , paint_widget_(new PaintWidget(this))
    , metrics_widget_(new MetricsWidget(this))
    , diagram_button_(new AnimatedButton("url(:/resources/images/diagram3.png)", "#74c2e1"))
    , graph_button_(new AnimatedButton("url(:/resources/images/graph4.png)", "#324a5e"))
    , paint_button_(new AnimatedButton("url(:/resources/images/brush3.png)", "#000000"))
    , settings_button_(new AnimatedButton("url(:/resources/images/gear7.png)", "#ffffff"))
    , tab_spacer_(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding))
    , view_settings_(new QSettings("School21", "MLP"))
    , fp_type_validator_(new QRegularExpressionValidator(QRegularExpression("[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?"), this))
    , int_type_validator_(new QRegularExpressionValidator(QRegularExpression("[0-9]*"), this))
{
    ui_->setupUi(this);
    InitDefaultUISettings_();
    ConnectUISlots_();
    RestoreViewSettings_();
}

MainWindow::~MainWindow()
{
    SaveViewSettings_();
    delete ui_;
    delete graph_widget_;
    delete paint_widget_;
    delete metrics_widget_;
    delete diagram_button_;
    delete graph_button_;
    delete paint_button_;
    delete settings_button_;
//    delete tab_spacer_; // почему-то из-за этого приложение завершается крашем при закрытии
    delete view_settings_;
    delete fp_type_validator_;
    delete int_type_validator_;
}

void MainWindow::BlockButtons_() {
    ui_->startTrainingButton->setEnabled(false);
    ui_->startTestButton->setEnabled(false);
    ui_->startCrossValidationButton->setEnabled(false);
}

void MainWindow::UnblockButtons_() {
    ui_->startTrainingButton->setEnabled(true);
    ui_->startTestButton->setEnabled(true);
    ui_->startCrossValidationButton->setEnabled(true);
}

void MainWindow::ReadModelSettings_()
{
    emit SetModelSettings(GetPerceptronSettings(), static_cast<ModelType>(ui_->modelType->currentIndex()));
}

void MainWindow::EmitStartTraining_()
{
    if (ui_->datasetTrainingPath->text().isEmpty())
    {
        ui_->browseDatasetForTraining->click();
    }
    else
    {
        std::string training_path = ui_->datasetTrainingPath->text().toStdString();
        std::size_t proportion = ui_->datasetProportion->value();
        std::size_t number_of_epochs = ui_->numberOfEpochs->text().toUInt();
        graph_widget_->Clear();
        metrics_widget_->Clear();
        graph_widget_->SetXRange(Const::target.second / Const::error_updates, number_of_epochs);
        emit StartTraining(training_path, number_of_epochs, proportion);
    }
}

void MainWindow::EmitStartTesting_()
{
    if (ui_->datasetTestsPath->text().isEmpty())
    {
        ui_->browseDatasetForTesting->click();
    }
    else
    {
        emit StartTesting(ui_->datasetTestsPath->text().toStdString());
    }
}

void MainWindow::EmitStartCrossValidation_()
{
    std::string dataset = ui_->datasetTrainingPath->text().toStdString();
    PerceptronSettings settings = GetPerceptronSettings();
    std::size_t groups = ui_->numberOfGroups->text().toUInt();
    std::size_t epochs = ui_->numberOfEpochs->text().toUInt();
    ModelType type = static_cast<ModelType>(ui_->modelType->currentIndex());

    graph_widget_->Clear();
    graph_widget_->SetXRange(Const::target.second / Const::error_updates, epochs * groups);
    metrics_widget_->Clear();
    emit StartCrossValidation(dataset, settings, groups, epochs, type);
}

void MainWindow::Manager_()
{
    if (model_is_setted_up_)
    {
        if (model_is_trained_)
        {
            QDialog* dialog_window = new QDialog(this);
            QPushButton* continue_training = new QPushButton("Continue training");
            QPushButton* new_model = new QPushButton("New model");
            QLabel* label = new QLabel("Your model is already trained.");
            QHBoxLayout* h_layout = new QHBoxLayout();
            QVBoxLayout* v_layout = new QVBoxLayout();

            label->setWordWrap(true);
            h_layout->addWidget(new_model);
            h_layout->addWidget(continue_training);
            v_layout->addWidget(label);
            v_layout->addLayout(h_layout);
            dialog_window->setLayout(v_layout);
            connect(continue_training, &QPushButton::clicked, this, [&]()
            {
                dialog_window->accept();
                EmitStartTraining_();
            });
            connect(new_model, &QPushButton::clicked, this, [&]()
            {
                dialog_window->accept();
                ReadModelSettings_();
                EmitStartTraining_();
            });
            dialog_window->exec();

            delete continue_training;
            delete new_model;
            delete label;
            delete h_layout;
            delete v_layout;
            delete dialog_window;
        }
        else
        {
            EmitStartTraining_();
        }
    }
    else
    {
        ReadModelSettings_();
        EmitStartTraining_();
    }
}

void MainWindow::AddErrorToGraph(double error, unsigned int epoch)
{
    graph_widget_->PushBack(error);
}

void MainWindow::SetMetrics(MappedLettersMetrics metrics)
{
    std::pair<QString, QString> pair_precision = MapToPairString_(metrics.precision_map);
    std::pair<QString, QString> pair_recall = MapToPairString_(metrics.recall_map);
    std::pair<QString, QString> pair_fmeasure = MapToPairString_(metrics.F1_map);

    ui_->accuracyValue->setText(QString::number(metrics.accuracy));
    ui_->precisionValue->setText(pair_precision.first);
    ui_->recallValue->setText(pair_recall.first);
    ui_->fMeasureValue->setText(pair_fmeasure.first);
    ui_->precisionValue->setToolTip(pair_precision.second);
    ui_->recallValue->setToolTip(pair_recall.second);
    ui_->fMeasureValue->setToolTip(pair_fmeasure.second);
    ui_->trainingTimeValue->setText(QString::number(metrics.training_time) + "ms");
    ui_->testingTimeValue->setText(QString::number(metrics.testing_time) + "ms");
}

std::pair<QString, QString> MainWindow::MapToPairString_(std::vector<std::pair<char, fp_type>> values)
{
    QString value_string("{");
    QString tool_tip_string;

    for (unsigned int i = 0; i < values.size(); ++i)
    {
        QString str = "'" + QString(values[i].first) + "': " + QString::number(values[i].second, 'f', 2) + ", ";

        tool_tip_string += str;
        if (i < MetricsConstants::kNumberOfLettersDisplayed)
        {
            value_string += str;
        }
    }
    tool_tip_string.chop(QString(", ").size());
    value_string.chop(QString(", ").size());
    value_string += " ...}";

    return { value_string, tool_tip_string };
}

void MainWindow::SetPredict(char c)
{
    paint_widget_->SetPredict(c);
}

PerceptronSettings MainWindow::GetPerceptronSettings()
{
    PerceptronSettings settings;

    for (auto item : ui_->layersListWidget->findItems("*", Qt::MatchWildcard))
    {
        settings.layers.push_back(item->text().toInt());
    }

    settings.SetActivation(static_cast<ActivationFunctions>(ui_->activationFunction->currentIndex()));
    settings.SetWeightInit(static_cast<WeightInitFunctions>(ui_->weightFunction->currentIndex()));
    settings.learning_rate = ui_->learningRate->text().toDouble();
    settings.momentum = ui_->momentum->text().toDouble();
    settings.lr_epoch_k = ui_->learningRateDecayByEpoch->text().toDouble();
    settings.lr_layers_k = ui_->learningRateDecayByLayer->text().toDouble();

    return settings;
}

void MainWindow::SetCrossMetrics(Metrics metrics)
{
    metrics_widget_->SetMetrics(metrics);
}

} // namespace s21
