#include "model/data_manager.h"
#include "model/matrix_model.h"
#include "lib/m_time.h"

// typedef double type;
using namespace s21;

int main() {

    int CROSS = 9;

    int layers = 4;

    size_vector layer_sizes1{Const::max_layer, 200, 150, 100, 50, Const::min_layer};
    fp_type learning_rate = 0.0075;
    MatrixModel MM(layer_sizes1, learning_rate);

    auto time_point = s21::Time::Now();




    // Learn
    {
        DataManager letters_train("../datasets/emnist-letters-train.csv", -1);
        letters_train.Shuffle();
        letters_train.Split(CROSS);
        std::cout << "Dataset time = " << s21::Time::Duration(time_point) << '\n';
        time_point = s21::Time::Now();
        MM.Learn(letters_train, 5);
        std::cout << "Learn time = " << s21::Time::Duration(time_point) << "\n\n";

        // auto metrics = MM.Test(letters_test1); //
    }

    //Test
    {
        time_point = s21::Time::Now();
        DataManager letters_test1("../datasets/emnist-letters-test.csv", -1);
        auto metrics = MM.Test(letters_test1);
        std::cout << metrics.accuracy << '\n';
        s21::SStr::Print(metrics.precision, metrics.recall, metrics.F1);
        std::cout << "Test time = " << s21::Time::Duration(time_point) << "\n\n";
    }

    return 0;
}


