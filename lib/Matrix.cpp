#include "Matrix.hpp"

template<typename T>
using vector2D = std::vector<std::vector<T>>;

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
Matrix<T>::Matrix(const vector2D<T>& vector_2d) :
num_rows(vector_2d.size()), num_cols(vector_2d.empty() ? 0u : vector_2d.front().size()), data(vector_2d) {}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> array_2d) : 
num_rows(array_2d.size()), num_cols(array_2d.size() == 0u ? 0u : array_2d.begin()->size()), data(num_rows, std::vector<T>(num_cols)) { 
  for (size_t row{0}; row < num_rows; row++) { 
    for (size_t col{0}; col < num_cols; col++) { 
      data[row][col] = *((*(array_2d.begin() + row)).begin() + col);
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