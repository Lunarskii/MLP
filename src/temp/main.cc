#include "../model/data_manager.h"
#include "../model/graph_model.h"
#include "../lib/m_time.h"
#include "../lib/m_sstr.h"

using namespace s21;

int main() {

    int CROSS = 9;

    int layers = 4;

    size_vector layer_sizes1{Const::max_layer, 200, 150, 100, 50, Const::min_layer};
    fp_type learning_rate = 0.0075;

    PerceptronSettings ps;
    ps.SetActivation(kSiLU);
    ps.layers = layer_sizes1;
    ps.learning_rate = learning_rate;
    ps.SetWeightInit(kXavier);
    ps.momentum = 0.15;


    auto time_point = s21::Time::Now();


    GraphModel MM(ps);
    // Learn
    {
        DataManager letters_train("../datasets/emnist-letters-train.csv", -1, k90Rotate);
        // DataManager letters_train("../datasets/a_z_data.csv", 0, 0);

        letters_train.Shuffle();

        // при вызове метода Split получаем долю тестовой выборки = 1/CROSS
        // letters_train.Split(CROSS);

        std::cout << "Dataset time = " << s21::Time::Duration(time_point) << '\n';
        time_point = s21::Time::Now();
        // обучение с использованием letters_train датасета и его обучающей доли (default 80%).
        MM.Learn(letters_train, 5);
        std::cout << "Learn time = " << s21::Time::Duration(time_point) << "\n\n";


        // TEST с использованием letters_train датасета и его тестовой доли (default 20%).
        auto metrics = MM.Test(letters_train);
        std::cout << metrics.accuracy << '\n';
        s21::SStr::Print(metrics.precision, metrics.recall, metrics.F1);
        std::cout << "Test time = " << s21::Time::Duration(time_point) << "\n\n";

    }
    // MM.ToFile("perceptron-q_z_data-1.prcp");


    // MatrixModel MM("perceptron1.prcp");

    //Test
    {
        time_point = s21::Time::Now();
        DataManager letters_test1("../datasets/emnist-letters-test.csv", -1, k90Rotate);
        auto metrics = MM.Test(letters_test1);
        std::cout << metrics.accuracy << '\n';
        s21::SStr::Print(metrics.precision, metrics.recall, metrics.F1);
        std::cout << "Test time = " << s21::Time::Duration(time_point) << "\n\n";
    }

    return 0;
}

