// #pragma once

#include <gtest/gtest.h>

#include "../../model/matrix_model.h"

using namespace s21;

auto rp = std::bind(SStr::RelativePath, __FILE__, std::placeholders::_1);

TEST(MatrixModelTest, FileConstructors) {
  MatrixModel MM(rp("../materials/perceptron1.prcp"));
  MM.ToFile("tmp.prcp");
  std::fstream file1("tmp.prcp");
  std::fstream file2(rp("../materials/perceptron1.prcp"));
  char c1, c2;
  while(file1.get(c1) && file2.get(c2)) {
    EXPECT_EQ(c1, c2);
  }
  EXPECT_EQ(file1.peek(), file2.peek());
  file1.close();
  file2.close();
  std::remove("tmp.prcp");
}

PerceptronSettings CorrectSettings() {
  PerceptronSettings PS;
  PS.layers = {784, 345, 26};
  PS.learning_rate = 0.5;
  PS.SetActivation(kSigmoid);
  PS.SetWeightInit(kXavier);
  return PS;
}

TEST(MatrixModelTest, SettingsConstructor) {
  EXPECT_NO_THROW(MatrixModel MM(CorrectSettings()));
}

TEST(MatrixModelTest, ErrorFileConstructor) {
  EXPECT_ANY_THROW(MatrixModel MM("123"));
  EXPECT_ANY_THROW(MatrixModel MM(rp("/../materials/bad_file_1.prcp")));
  EXPECT_ANY_THROW(MatrixModel MM(rp("/../materials/bad_file_2.prcp")));
  EXPECT_ANY_THROW(MatrixModel MM(rp("/../materials/bad_file_3.prcp")));
  EXPECT_ANY_THROW(MatrixModel MM(rp("/../materials/empty_file.prcp")));
}

void IncorrectSettingsTest(std::function<void(PerceptronSettings&)> set) {
  auto PS = CorrectSettings();
  set(PS);
  EXPECT_ANY_THROW(MatrixModel MM(PS));
}

TEST(MatrixModelTest, ErrorSettingsConstructor1) {
  IncorrectSettingsTest(
    [] (PerceptronSettings &PS) { PS.layers = {}; });
  IncorrectSettingsTest(
    [] (PerceptronSettings &PS) { PS.learning_rate = 0.0; });
  IncorrectSettingsTest(
    [] (PerceptronSettings &PS) { PS.learning_rate = -1.9; });
  IncorrectSettingsTest(
    [] (PerceptronSettings &PS) { PS.lr_epoch_k = -0.1; });
  IncorrectSettingsTest(
    [] (PerceptronSettings &PS) { PS.lr_layers_k = -0.4; });
}

TEST(MatrixModelTest, ErrorSettingsConstructor2) {
  PerceptronSettings PS;
  PS.layers = {784, 345, 26};
  PS.learning_rate = 0.5;
  PS.SetActivation(kSigmoid);
  EXPECT_ANY_THROW(MatrixModel MM(PS));
}

TEST(MatrixModelTest, ErrorSettingsConstructor3) {
  PerceptronSettings PS;
  PS.layers = {784, 345, 26};
  PS.learning_rate = 0.5;
  PS.SetWeightInit(kXavier);
  EXPECT_ANY_THROW(MatrixModel MM(PS));
}

TEST(MatrixModelTest, ErrorSettingsConstructor4) {
  PerceptronSettings PS;
  EXPECT_ANY_THROW(MatrixModel MM(PS));
}

TEST(MatrixModelTest, LearnTest) {
  // MatrixModel MM(CorrectSettings());
  // DataManager DM("materials/letters");
  // MM.Learn(DM, 1);
  // auto metrics = MM.Test(DM);
  // EXPECT_EQ(metrics.accuracy, 0.0);
  // EXPECT_EQ(metrics.precision.size(), 26);
  // for (auto i : metrics.precision) {
  //   EXPECT_EQ(i, 0.0);
  // }
}



