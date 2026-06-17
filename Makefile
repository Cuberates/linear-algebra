CXX      = g++
CXXFLAGS = -std=c++2b -Wall -Wextra -pedantic
SRC_MAIN = tests/MatrixTests.cpp
BIN_MAIN = tests/MatrixTests.o

build:
	$(CXX) $(CXXFLAGS) $(SRC_MAIN) -lgtest -lgtest_main -o $(BIN_MAIN)

test: build
	./$(BIN_MAIN)

clean:
	rm -f $(BIN_MAIN) $(BIN_FMAT)
