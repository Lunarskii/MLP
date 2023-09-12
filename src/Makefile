.PHONY: all install uninstall clean dvi dist launch tests style valgrind

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
