CXX      = g++
CXXFLAGS = -std=c++2b -Wall -Wextra -pedantic
SRC_MAIN = tests/main.cpp
SRC_FMAT = tests/fmat.cpp
BIN_MAIN = tests/main.o
BIN_FMAT = tests/fmat.o

build:
	$(CXX) $(CXXFLAGS) $(SRC_MAIN) -o $(BIN_MAIN)

build-fmat:
	$(CXX) $(CXXFLAGS) $(SRC_FMAT) -o $(BIN_FMAT)

test: build
	./$(BIN_MAIN)

test-fmat: build-fmat
	./$(BIN_FMAT)

test-all: test test-fmat

test-asan:
	$(CXX) $(CXXFLAGS) -fsanitize=address,undefined -fno-omit-frame-pointer -g $(SRC_MAIN) -o $(BIN_MAIN)
	./$(BIN_MAIN)
	$(CXX) $(CXXFLAGS) -fsanitize=address,undefined -fno-omit-frame-pointer -g $(SRC_FMAT) -o $(BIN_FMAT)
	./$(BIN_FMAT)

clean:
	rm -f $(BIN_MAIN) $(BIN_FMAT)
