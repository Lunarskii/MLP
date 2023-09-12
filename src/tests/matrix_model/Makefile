CC=g++
FLAGS=-Wall -Werror -Wextra
TESTFLAGS=-lgtest_main -lgtest -pthread
SRC=matrix_model_test.cc ../../model/matrix_model.cc ../../model/data_manager.cc ../../common/metrics.cc ../../common/perceptron_settings.cc ../../common/error_thread.cc
EXEC=matrix_model_test


all:
	$(CC) $(FLAGS) $(SRC) -lblas $(TESTFLAGS) -o $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
