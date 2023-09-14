.PHONY: matrix_model_test graph_model_test clean

CC=g++
FLAGS=-Wall -Werror -Wextra
TESTFLAGS=-lgtest_main -lgtest -pthread
SRC=../common/metrics.cc ../common/perceptron_settings.cc ../common/error_thread.cc ../model/data_manager.cc
MM_SRC=$(SRC) matrix_model_test.cc ../model/matrix_model.cc
GM_SRC=$(SRC) graph_model_test.cc ../model/graph_model.cc
OPTIMIZATION=-Ofast -march=native


matrix_model_test:
	$(CC) $(FLAGS) $(MM_SRC) $(TESTFLAGS) -o matrix_model_test $(OPTIMIZATION)
	./matrix_model_test

graph_model_test:
	$(CC) $(FLAGS) $(GM_SRC) $(TESTFLAGS) -o graph_model_test $(OPTIMIZATION)
	./graph_model_test

clean:
	rm -f matrix_model_test
	rm -f graph_model_test
