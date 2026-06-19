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
  num_rows = vdata.size(); 
  num_cols = ((*vdata.begin()).size()); 
  
  data = std::vector<std::vector<T>>(num_rows, std::vector<T>(num_cols));
  
  for (std::size_t r = 0; r < num_rows; ++r) {
    for (std::size_t c = 0; c < num_cols; ++c) { 
      data[r][c] = vdata[r][c];
    }
  }
}
template<typename T> 
T& Matrix<T>::operator () (size_t i, size_t j) { 
return data[i][j];
}

template<typename T>
const T& Matrix<T>::operator () (size_t i, size_t j) const { 
  return data[i][j];
}

template<typename T> 
size_t Matrix<T>::numCols() const { 
  return num_cols; 
}
template<typename T> 
size_t Matrix<T>::numRows() const { 
  return num_rows; 
}