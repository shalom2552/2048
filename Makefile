CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

SRC = main.cpp \
	  $(wildcard src/*.cpp) \
	  $(wildcard src/display/*.cpp) \
	  $(wildcard src/menu/*.cpp)
OBJ = $(SRC:.cpp=.o)
TRG = game


all: $(TRG)

$(TRG): $(OBJ)
	g++ -o $(TRG) $(OBJ)

clean:
	$(RM) $(OBJ) $(TRG)
