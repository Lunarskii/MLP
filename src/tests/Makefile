.PHONY: file_test clean speed_test settings_test

CC=g++
FLAGS=-Wall -Werror -Wextra
TESTFLAGS=-lgtest_main -lgtest -pthread
SRC=../common/metrics.cc ../common/perceptron_settings.cc ../common/error_thread.cc ../model/data_manager.cc ../model/model.cc ../model/matrix_model.cc ../model/graph_model.cc
MM_SRC=../model/matrix_model.cc
GM_SRC=../model/graph_model.cc
OPTIMIZATION=-Ofast -march=native



file_test:
	$(CC) $(FLAGS) $(SRC) file.cc $(TESTFLAGS) -o file_test $(OPTIMIZATION)
	./file_test

speed_test:
	$(CC) $(FLAGS) $(SRC) speed.cc -o speed_test $(OPTIMIZATION)
	./speed_test

settings_test:
	$(CC) $(FLAGS) $(SRC) settings.cc $(TESTFLAGS) -o settings_test $(OPTIMIZATION)
	./settings_test

clean:
	rm -f file_test
	rm -f speed_test
	rm -f settings_test
