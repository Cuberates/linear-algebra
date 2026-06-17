#ifndef MATRIX_H
#define MATRIX_H
#include <vector> 
#include <algorithm>
#include <cmath>

template <typename T> 
class Matrix { 
  private: 
  size_t num_rows; 
  size_t num_cols; 
  std::vector<std::vector<T>> data;

  public:
  size_t numCols() const;
  size_t numRows() const;
  Matrix(); 
  Matrix(size_t dimension); 
  Matrix(size_t rows, size_t cols); 
  Matrix(const std::vector<std::vector<T>> & vdata); 

  T& operator() (size_t i, size_t j) const; 
  T& operator() (size_t i, size_t j);  
};

#endif