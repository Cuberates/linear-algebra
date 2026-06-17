#include "../lib/Matrix.hpp"

template<typename T> 
Matrix<T>::Matrix() : 
  num_rows(0u), num_cols(0u) {}

template<typename T> 
Matrix<T>::Matrix(std::size_t rows, std::size_t cols) : 
  num_rows(rows), num_cols(cols), data(rows, std::vector<T>(cols)) {}

template<typename T> 
Matrix<T>::Matrix(std::size_t dimension) : 
  Matrix(dimension, dimension) {}

template<typename T> 
Matrix<T>::Matrix(const std::vector<std::vector<T>>& vdata) { 
  std::size_t sz_row = vdata.size(); 
  std::size_t sz_col = ((*vdata.begin()).size());
   
  data = std::vector<std::vector<T>>(sz_row, std::vector<T>(sz_col));
  
  for (std::size_t r = 0; r < sz_row; ++r) {
    for (std::size_t c = 0; c < sz_col; ++c) { 
      data[r][c] = vdata[r][c];
    }
  }
}
template<typename T> 
size_t Matrix<T>::numCols() const { 
  return num_cols; 
}
template<typename T> 
size_t Matrix<T>::numRows() const { 
  return num_rows; 
}
