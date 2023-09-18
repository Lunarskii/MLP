.PHONY: all install uninstall clean dvi dist launch tests style valgrind speed_test dvi

SRC=model/data_manager.cc model/matrix_model.cc model/graph_model.cc model/model.cc common/perceptron_settings.cc common/error_thread.cc common/metrics.cc
OPTIMIZATION=-Ofast -march=native
STANDART=-std=c++17


APP_NAME = MLP

OS := $(shell uname -s)
ifeq ($(OS), Linux)
	OPEN = ./build/$(APP_NAME)
endif
ifeq ($(OS), Darwin)
	OPEN = open build/$(APP_NAME).app
endif

all: install launch

install:
	cmake -B build
	make -C build $(APP_NAME)

uninstall:
	rm -rf build

launch:
	$(OPEN)

console:
	g++ main_console.cc $(SRC) $(OPTIMIZATION) $(STANDART) -o console
	./console

dvi:
	mkdir -p documentation
	@doxygen Doxyfile && mv html documentation && mv latex documentation
	@open documentation/html/index.html


clean: uninstall
	rm -rf console
	rm -rf speed_test
	rm -rf documentation
