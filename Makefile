GPP = g++
SFML_VERSION = 2.5.1

SFML_LIB = /usr/local/lib/SFML-$(SFML_VERSION)/lib
SFML_HEADERS = /usr/local/lib/SFML-$(SFML_VERSION)/include

FLAGS = -Wall -L $(SFML_LIB) -I $(SFML_HEADERS)
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
CPP = editor.cpp $(wildcard editor/*.cpp)
BIN = loop

.PHONY: all loop clean
create:
	$(GPP) $(FLAGS) -o $(BIN) $(CPP) $(LIBS)
	./$(BIN)

remove:
	rm -r ./$(BIN)