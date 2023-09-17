#include "test.h"

#include "../lib/m_time.h"

using namespace s21;

int main() {
    MatrixModel MM(rp("materials/perceptron_matrix.prcp"));
    GraphModel GM(rp("materials/perceptron_matrix.prcp"));
    DataManager letters_test(rp("datasets/emnist-letters-train.csv"), -1, k90Rotate);
    letters_test.Split(15);


    for (auto iter : {10, 100, 1000}) {
        auto result = Time::Compare(iter, [&] {
            MM.Test(letters_test);
        }, [&] {
            GM.Test(letters_test);
        });
        std::cout << "\033[1;32m" << iter << " iterations:\033[0m\n";
        std::cout << "\tMatrix: " << result[0] << "\n";
        std::cout << "\tGraph: " << result[1] << "\n";
    }
    return 0;
}
