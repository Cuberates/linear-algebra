CXX      = g++
CXXFLAGS = -std=c++2b -Wall -Wextra -pedantic -lgtest -lgtest_main -O0 

SRCS = matrix.cpp 
HEADERS = matrix.hpp

build:
	$(CXX) $(CXXFLAGS) ${SRCS} -o ${SRCS:.cpp=.o}

clean:	
	rm -r -f *.o
