CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

SRC = main.cpp ./src/board.cpp ./src/game.cpp ./src/display/board_display.cpp ./src/input.cpp
OBJ = $(SRC:.cpp=.o)
TRG = game


all: $(TRG)

$(TRG): $(OBJ)
	g++ -o $(TRG) $(OBJ)

clean:
	$(RM) $(OBJ) $(TRG)
