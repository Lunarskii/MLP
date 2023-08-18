#include "data_manager.h"

using namespace s21;

DataManager::DataManager(const std::string &file_path, int bias) :
        letters_(Const::min_layer) {
    std::fstream file(file_path);
    while (file) {
        int name;
        file >> name;
        name += bias;
        file.ignore();
        letters_[name].emplace_back(Const::max_layer);
        Read(file, letters_[name].back());
        ++size_;
    }
    file.close();

    // for (int k = 0; k < 10; ++k) {
    //     int name = Random::Int<int>(0, Const::min_layer - 1);
    //     PrintLetter(letters_[name][Random::Int<int>(0, letters_[name].size() * train_proportion_)]);
    // }
}

void DataManager::ForTest(const std::function<void(data_vector&, int)> func) {
    for (int name = 0; name < Const::min_layer; ++name) {
        for (auto iter = letters_[name].end() - letters_[name].size() * test_proportion_;
                iter != letters_[name].end(); ++iter) {
            func(*iter, name);
        }
    }
}

void DataManager::ForTrain(const std::function<void(data_vector&, int)> func) {
    std::vector<bool> trained(Const::min_layer, false);

    // std::vector<int> counts(Const::min_layer, 0);

    for (int k = 0; k < size_ * train_proportion_; ++k) {
        fp_type selection = s21::Random::Uniform<fp_type>(0.0, metric_sum_);
        for (int name = 0; name < Const::min_layer; ++name) {
            selection -= metric_[name];
            if (selection <= 0.0) {
                trained[name] = true;

                // ++counts[name];

                func(letters_[name][Random::Int<int>(0, letters_[name].size() * train_proportion_)], name);
                break;
            }
        }
        // int name = Random::Int<int>(0, Const::min_layer - 1);
        // func(letters_[name][Random::Int<int>(0, letters_[name].size() * train_proportion_)], name);
    }
    for (int name = 0; name < Const::min_layer; ++name) {

        // std::cout << counts[name] << ' ';

        if (!trained[name]) {
            func(letters_[name][Random::Int<int>(0, letters_[name].size() * train_proportion_)], name);
        }
    }

    std::cout << '\n';
}

void DataManager::Split(int proportion) {
    metric_ = std::vector<fp_type>(Const::min_layer, 1.0);
    metric_sum_ = Const::min_layer;
    test_proportion_ = 1.0 / (fp_type)proportion;
    train_proportion_ = 1.0 - test_proportion_;
    cross_k_ = proportion - 1;
}

void DataManager::SetMetric(const std::vector<fp_type> &metric) {
    metric_sum_ = 0.0;
    for (int k = 0; k < Const::min_layer; ++k) {
        metric_[k] = 1.0 / metric[k];
        metric_sum_ += metric_[k];
    }
}

void DataManager::Shuffle() {
    for (auto iter = letters_.begin(); iter != letters_.end(); ++iter) {
        std::shuffle(iter->begin(), iter->end(),
            std::default_random_engine(std::random_device{}()));
    }
}

void DataManager::CrossUpdate() {
    if (cross_k_ == 0) {
        std::cout << "cros_k == 0\n";
        return;
    }
    for (int name = 0; name < Const::min_layer; ++name) {
        int end = cross_k_ * letters_[name].size() * test_proportion_;
        int start = (cross_k_ - 1) * letters_[name].size() * test_proportion_;
        std::rotate(letters_[name].begin() + start, letters_[name].begin() + end, letters_[name].end());
    }
    --cross_k_;
}

void DataManager::PrintLetter(const data_vector &one) {
    auto iter = one.begin();
    for (int k = Const::letter_height - 1; k != -1; --k) {
        for (int g = 0; g < Const::letter_width; ++g) {
            if (*iter > 0.2)
                printf("\033[0;31m");
            else
                printf("\033[0m");
            printf("%2.2f", *iter);
            ++iter;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


