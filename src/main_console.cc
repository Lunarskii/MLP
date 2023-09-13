#include "model/data_manager.h"
#include "model/matrix_model.h"
#include "model/graph_model.h"
#include "lib/m_time.h"

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

    MatrixModel MM(ps);

    // Learn
    {
        DataManager letters_train("../datasets/emnist-letters-train.csv", -1, k90Rotate);

        letters_train.Shuffle();

        MM.SetErrorThread([] (fp_type error, unsigned int epoch) {
            std::cout << "epoch = " << epoch << " error = " << error << '\n';
        });
        MM.SetMetricThread([] (Metrics metrics) {
            std::cout << "accuracy = " << metrics.accuracy << '\n';
            std::cout << "train time " << metrics.train_time << '\n';
            std::cout << "test time " << metrics.test_time << '\n';

        });

        MM.Learn(letters_train, 4);
 
        auto metrics = MM.Test(letters_train);
        std::cout << metrics.accuracy << '\n';
        s21::SStr::Print(metrics.precision, metrics.recall, metrics.F1);

    }
    // MM.ToFile("perceptron-q_z_data-1.prcp");


    // MatrixModel MM("perceptron1.prcp");

    //Test
    // {
    //     time_point = s21::Time::Now();
    //     DataManager letters_test1("../datasets/emnist-letters-test.csv", -1, k90Rotate);
    //     auto metrics = MM.Test(letters_test1);
    //     std::cout << metrics.accuracy << '\n';
    //     s21::SStr::Print(metrics.precision, metrics.recall, metrics.F1);
    //     std::cout << "Test time = " << s21::Time::Duration(time_point) << "\n\n";
    // }

    return 0;
}


