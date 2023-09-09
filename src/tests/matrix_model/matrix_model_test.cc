// #pragma once

#include <gtest/gtest.h>

#include "../../model/matrix_model.h"

using namespace s21;

TEST(MatrixModelTest, Constructors) {
  MatrixModel MM("materials/perceptron1.prcp");
  MM.ToFile("materials/perceptron1_tmp.prcp");
  std::fstream file1("materials/perceptron1_tmp.prcp");
  std::fstream file2("materials/perceptron1.prcp");
  char c1, c2;
  while(file1.get(c1) && file2.get(c2)) {
    EXPECT_EQ(c1, c2);
  }
  EXPECT_EQ(file1.operator bool(), file2.operator bool());
  file1.close();
  file2.close();
  std::remove("materials/perceptron1_tmp.prcp");
}



