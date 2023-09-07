

all: clean
	g++ main.cc lib/m_thread.cc common/metrics.cc model/data_manager.cc model/matrix_model.cc common/perceptron_settings.cc -lpthread -lm -ldl -lblas -Ofast -march=native
	./a.out


clean:
	rm -rf a.out
