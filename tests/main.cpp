#include "../lib/matrices.h"
#include <iostream> 
#include <cassert>

namespace MatrixTest { 
  bool test_create() { 
    uint32_t csize = 10; 
    uint32_t rsize = 10; 
    float val = 1.0;
    Matrix<float> mat(rsize, csize, val);
    std::pair<uint32_t, uint32_t> sz = dim(mat);
    assert(sz.first == rsize);
    assert(sz.second == csize);
    return 1;
  }
}

int main(void) { 
  
  return 0; 
}