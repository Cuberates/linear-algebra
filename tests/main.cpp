#include "../lib/matrices.h"
#include <iostream> 
#include <cassert>

int main(void) { 
  Matrix<uint32_t> mat(5, 5, 10);
  std::cout << mat.getCols() << "\n";
  std::cout << mat.getRows() << "\n";
  return 0; 
}