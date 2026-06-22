CXX      = g++
CXXFLAGS = -std=c++2b -Wall -Wextra -pedantic -lgtest -lgtest_main -O0 

# Sources
src_matrix_test = tests/MatrixTests
src_arithmetics_test = tests/ArithmeticsTests

build:
	$(CXX) $(CXXFLAGS) $(src_matrix_test).cpp -o $(src_matrix_test).o
	$(CXX) $(CXXFLAGS) $(src_arithmetics_test).cpp -o $(src_arithmetics_test).o


test: build
	./$(src_matrix_test).o && rm -r -f $(src_matrix_test).o
	./$(src_arithmetics_test).o && rm -r -f $(src_arithmetics_test).o
		
clean:
	rm -r -f ${src_matrix_test}.o
	rm -r -f ${src_arithmetics_test}.o