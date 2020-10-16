GPP = g++
SDL_VERSION = 2.0.0

FLAGS = -w
LINKER_FLAGS = -lSDL2 -lSDL2_ttf
EXEC = loop

CPP = main.cpp $(wildcard editor/*.cpp)

.PHONY: all loop clean
all :
	$(GPP) $(CPP) $(FLAGS) $(LINKER_FLAGS) -o $(EXEC)
	./$(EXEC)