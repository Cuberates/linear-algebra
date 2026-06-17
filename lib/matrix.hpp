#include <vector> 
#include <algorithm>
#include <cmath>

template <typename T> 
class Matrix { 
  private: 
  size_t num_rows; 
  size_t num_cols; 
  std::vector<T> data;

  public:
  size_t numCols() const { return num_cols; }
  size_t numRows() const { return num_rows; }
  
  Matrix() : num_rows(0), num_cols(0) {}
  
  Matrix(size_t dimension) : Matrix(dimension, dimension) {}
  
  Matrix(size_t rows, size_t cols) : 
    num_rows(rows), num_cols(cols), data(rows * cols) {}
  
  Matrix(size_t rows, size_t cols, const std::vector<T>& v_data) : 
    num_rows(rows), num_cols(cols), data(v_data) {}
};