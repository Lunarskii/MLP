#include "data_manager.h"


int main() {
    // s21::DataManager manager("../../datasets/a_z_data.csv", 0, 0);
    s21::DataManager manager("../../datasets/emnist-letters-train.csv", -1, -1);
    manager.Printn(20);
    
    return 0;
}
