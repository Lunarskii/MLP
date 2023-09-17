#include "mainwindow.h"

namespace s21 
{

void MainWindow::ChangeApplicationTab_()
{
    ui_->applicationTabWidget->setCurrentIndex(!ui_->applicationTabWidget->currentIndex());
}

void MainWindow::OpenCSVFile_(QLineEdit& line, QString msg)
{
    QString file_path = QFileDialog::getOpenFileName(this, msg, "./", "Dataset files (*.csv);; All Files (*)");

    if (!file_path.isEmpty())
    {
        line.setText(file_path);
    }
}

void MainWindow::AddLayer_()
{
    if (ui_->layersListWidget->count() != 7)
    {
        int row = ui_->layersListWidget->currentRow();

        if (row == 0)
        {
            ++row;
        }
        else if (row == -1)
        {
            row = ui_->layersListWidget->count() - 1;
        }

        ui_->layersListWidget->resize(ui_->layersListWidget->width(), ui_->layersListWidget->height() + size_list_widget_item_);
        ui_->layersListWidget->insertItem(row, "0");
        QListWidgetItem* item = ui_->layersListWidget->item(row);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
}

void MainWindow::RemoveLayer_()
{
    int row = ui_->layersListWidget->currentRow();
    std::size_t size = ui_->layersListWidget->count();

    if (row != 0 && row != size - 1 && size != 2)
    {
        if (row != -1)
        {
            ui_->layersListWidget->takeItem(row);
        }
        else
        {
            ui_->layersListWidget->takeItem(size - 2);
        }
        ui_->layersListWidget->resize(ui_->layersListWidget->width(), ui_->layersListWidget->height() - size_list_widget_item_);
    }
}

} // namespace s21
