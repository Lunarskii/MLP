#include "data_manager.h"

using namespace s21;

int main() {
    // s21::DataManager manager("../../datasets/a_z_data.csv", 0, 0);
    DataManager manager("../../datasets/emnist-letters-train.csv", -1, kNoRotate);
    manager.Printn(5);
    std::cout << "--------------\n";
    DataManager manager1("../../datasets/emnist-letters-train.csv", -1, k90Rotate);
    manager1.Printn(5);

    return 0;
}
