CXX      = g++
CXXFLAGS = -std=c++2b -Wall -Wextra -pedantic -lgtest -lgtest_main -O0 

SRCS = matrix_tests.cpp

build:
	$(CXX) $(CXXFLAGS) ${SRCS} -o ${SRCS:.cpp=.o}

test: build 
	./${SRCS:.cpp=.o}

clean:	
	rm -r -f *.o

