CXX      = g++
CXXFLAGS = -std=c++2b -Wall -Wextra -pedantic
SRC      = tests/main.cpp
BIN      = tests/main.o

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

clean:
	rm -f $(BIN)
