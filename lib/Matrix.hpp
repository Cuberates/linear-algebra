#ifndef MATRIX_H
#define MATRIX_H
#include <vector> 
#include <algorithm>
#include <cmath>

template<typename T>
using vector2D = std::vector<std::vector<T>>;

template <typename T> 
class Matrix {
  private: 
  size_t num_rows; 
  size_t num_cols; 
  vector2D<T> data; 
  public:
  [[nodiscard]]
  size_t numCols() const;
  [[nodiscard]]
  size_t numRows() const;
  Matrix(); 
  Matrix(size_t dimension); 
  Matrix(size_t rows, size_t cols); 
  Matrix(const vector2D<T>& vector_2d);
  Matrix(std::initializer_list<std::initializer_list<T>> array_2d);
  const T& operator() (size_t i, size_t j) const;  
  T& operator() (size_t i, size_t j); 
};
#endif