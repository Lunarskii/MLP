#include <gtest/gtest.h>

#include "../model/graph_model.h"
#include "../lib/m_sstr.h"

using namespace s21;

auto rp = std::bind(SStr::RelativePath, __FILE__, std::placeholders::_1);

PerceptronSettings CorrectSettings() {
  PerceptronSettings PS;
  PS.layers = {784, 345, 26};
  PS.learning_rate = 0.5;
  PS.SetActivation(kSigmoid);
  PS.SetWeightInit(kXavier);
  return PS;
}

TEST(MatrixModelTest, FileConstructors) {
    GraphModel GM(rp("materials/perceptron1.grp"));
    GM.ToFile("tmp.prcp");
    std::fstream file1("tmp.prcp");
    std::fstream file2(rp("materials/perceptron1.grp"));
    char c1, c2;
    while(file1.get(c1) && file2.get(c2)) {
        EXPECT_EQ(c1, c2);
    }
    EXPECT_EQ(file1.peek(), file2.peek());
    file1.close();
    file2.close();
    std::remove("tmp.prcp");
}

