CXX      = g++
CXXFLAGS = -std=c++2b -Wall -Wextra -pedantic
SRC_MAIN = tests/main.cpp
BIN_MAIN = tests/main.o

build:
	$(CXX) $(CXXFLAGS) $(SRC_MAIN) -o $(BIN_MAIN)

test: build
	./$(BIN_MAIN)

clean:
	rm -f $(BIN_MAIN) $(BIN_FMAT)
