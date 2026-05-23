#include <iostream> 
#include <vector>

using Dimension = std::pair<size_t, size_t>;

template<typename T> 
using Array2D = std::vector<std::vector<T>>;

template<typename T>
using Array = std::vector<T>;

template<typename T>
class Matrix;

template<typename T>
Dimension matrix_size(const Matrix<T>& mat);
template<typename T>
void matrix_fill(Matrix<T>& mat, const T& data);
template<typename T>
void matrix_eq(Matrix<T>& mat, const Matrix<T>& eq_mat);
template<typename T>
void matrix_add(Matrix<T>& mat, const Matrix<T>& add_mat);
template<typename T>
void matrix_subtr(Matrix<T>& mat, const Matrix<T>& subtr_mat);
template<typename T>
void matrix_mul(Matrix<T>& mat, const Matrix<T>& mul_mat);
template<typename T>
void matrix_set(Matrix<T>& mat, const size_t& row, const size_t& col, const T& data);


template<typename T>
class Matrix {
  public:  

  Matrix(size_t numRows, size_t numCols, const T& data);
  Matrix(size_t numRows, size_t numCols, const std::vector<std::vector<T>>& array_2d); 
  Matrix(const Matrix<T>& mat);
  ~Matrix();

  std::vector<T>& operator[](size_t row) { return data[row]; }
  const std::vector<T>& operator[](size_t row) const { return data[row]; }

  friend Dimension matrix_size<>(const Matrix<T>& mat); 

  friend void matrix_fill<>(Matrix<T>& mat, const T& data);
  friend void matrix_eq<>(Matrix<T>& mat, const Matrix<T>& eq_mat);
  friend void matrix_add<>(Matrix<T>& mat, const Matrix<T>& add_mat);
  friend void matrix_subtr<>(Matrix<T>& mat, const Matrix<T>& subtr_mat);
  friend void matrix_mul<>(Matrix<T>& mat, const Matrix<T>& mul_mat);
  friend void matrix_set<>(Matrix<T>& mat, const size_t& row, const size_t& col, const T& data);
  
  private:   
  size_t numRows; 
  size_t numCols; 
  std::vector<std::vector<T>> data; 
};


template<typename T> 
Matrix<T>::Matrix(size_t numRows, size_t numCols, const T& data) : 
  numRows(numRows), numCols(numCols), data(std::vector<std::vector<T>>(numRows, std::vector<T>(numCols, data))) {}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& mat) { 
  Dimension sz_mat = matrix_size(mat);
  numRows = sz_mat.first; 
  numCols = sz_mat.second; 

  data = std::vector<std::vector<T>>(numRows, std::vector<T>(numCols));
  
  for(size_t row = 0; row < numRows; row++) { 
    for(size_t col = 0; col < numCols; col++) {
      data[row][col] = mat[row][col];
    }
  }
}

template<typename T>
Matrix<T>::~Matrix() = default;

template<typename T>
Dimension matrix_size(const Matrix<T>& mat) {
  return { mat.numRows, mat.numCols };
}

template<typename T>
void matrix_set(Matrix<T>& mat, const size_t& row, const size_t& col, const T& value) {
  mat.data[row][col] = value;
}

template<typename T>
Matrix<T>::Matrix(size_t numRows, size_t numCols, const std::vector<std::vector<T>>& vec_data) :
  numRows(numRows), numCols(numCols), data(vec_data) {}

template<typename T>
void matrix_fill(Matrix<T> &mat, const T& val) { 
  Dimension sz_mat = matrix_size(mat);

  const size_t& numRows = sz_mat.first; 
  const size_t& numCols = sz_mat.second;  

  for(size_t row = 0; row < numRows; row++) { 
    for(size_t col = 0; col < numCols; col++) {
      matrix_set(mat, row, col, val);
    }
  }
}

template<typename T> 
void matrix_add(Matrix<T> &mat, const Matrix<T>& add_mat) { 
  const Dimension & sz_mat = matrix_size(mat);
  const Dimension & sz_add_mat = matrix_size(add_mat);

  if (sz_mat.first != sz_add_mat.first) return; 
  if (sz_mat.second != sz_add_mat.second) return;

  for(size_t row = 0; row < sz_mat.first; row++) { 
    for(size_t col = 0; col < sz_mat.second; col++) { 
      mat[row][col] += add_mat[row][col];
    }
  }
}

template<typename T> 
void matrix_subtr(Matrix<T> &mat, const Matrix<T>& subtr_mat) { 
  const Dimension & sz_mat = matrix_size(mat);
  const Dimension & sz_subtr_mat = matrix_size(subtr_mat);  
  
  if (sz_mat.first != sz_subtr_mat.first) return; 
  if (sz_mat.second != sz_subtr_mat.second) return; 

  for(size_t row = 0; row < sz_mat.first; row++) { 
    for(size_t col = 0; col < sz_mat.second; col++) { 
      mat[row][col] -= subtr_mat[row][col];
    }
  }
}


template<typename T>
void matrix_mul(Matrix<T> &mat, const Matrix<T>& mul_mat) {
  const Matrix<T> lhs(mat);

  const Dimension & sz_mat = matrix_size(mat);
  const Dimension & sz_mul_mat = matrix_size(mul_mat);

  if(sz_mat.second != sz_mul_mat.first) return;

  mat.numRows = sz_mat.first; 
  mat.numCols = sz_mul_mat.second; 
  
  mat.data = std::vector<std::vector<T>>(mat.numRows, std::vector<T>(mat.numCols));

  for(size_t row = 0; row < mat.numRows; row++) { 
    for(size_t col = 0; col < mat.numCols; col++) {
      T sum = T{};
      for(size_t k = 0; k < sz_mat.second; k++) { 
        sum += (lhs[row][k] * mul_mat[k][col]);
      }
      mat[row][col] = sum;
    }
  }  
}