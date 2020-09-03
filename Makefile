GPP = g++
SFML_VERSION=2.5.1

SFML_LIB=/usr/local/lib/SFML-$(SFML_VERSION)/lib
SFML_HEADERS=/usr/local/lib/SFML-$(SFML_VERSION)/include

FLAGS = -std=c++11 -Wall -L $(SFML_LIB) -I $(SFML_HEADERS)
LIBS= -lsfml-graphics -lsfml-window -lsfml-system

# Final binary
BIN = editor

# Put all auto generated stuff to this build dir.
BUILD_DIR = ./build

# List of all .cpp source files.
# CPP = main.cpp $(wildcard dir1/*.cpp) $(wildcard dir2/*.cpp)
CPP = Editor.cpp $(wildcard src/*.cpp)

