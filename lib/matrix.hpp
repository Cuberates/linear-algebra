#include <iostream>
#include <algorithm>
#include <vector>

using Matrix = std::vector<std::vector<float>>;

namespace linalg { 
  Matrix mul(const Matrix& mat1, const Matrix& mat2);
  Matrix add(const Matrix& mat1, const Matrix& mat2);
  Matrix tr(const Matrix& mat1);
  Matrix diag(const Matrix& mat1);
  Matrix identity(size_t n);
  Matrix zeros(size_t n, size_t m);
  Matrix ones(size_t n, size_t m);
  Matrix rand(size_t n, size_t m);
  Matrix randn(size_t n, size_t m);
}

