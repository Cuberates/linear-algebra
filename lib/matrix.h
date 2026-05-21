#include <iostream> 
#include <vector>

template<typename T>
class Matrix {
  public: 
  Matrix(size_t numRows, size_t numCols, const T& data);  
  Matrix(const Matrix<T>& mat);
  ~Matrix();

  friend std::pair<size_t, size_t> & matrix_size(const Matrix<T>& mat); 

  friend void matrix_fill(Matrix<T>& mat, const T& data);
  friend void matrix_eq(Matrix<T>& mat, const Matrix<T>& eq_mat);
  friend void matrix_add(Matrix<T>& mat, const Matrix<T>& add_mat);
  friend void matrix_subtr(Matrix<T> &mat, const Matrix<T>& subtr_mat);
  friend void matrix_mul(Matrix<T>& mat, const Matrix<T>& mul_mat);

  friend T& matrix_get(const Matrix<T>& mat, const size_t& row, const size_t& col);
  friend void matrix_set(Matrix<T>& mat, const size_t& row, const size_t& col, const T& data);

  private:   
  size_t numRows; 
  size_t numCols; 
  std::vector<T> data; 
};

template<typename T> 
Matrix<T>::Matrix(size_t numRows, size_t numCols, const T& data) : 
  numRows(numRows), numCols(numCols), data(std::vector<std::vector<T>>(numRows, std::vector<T>(numCols, data))) {}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& mat) { 
  std::pair<size_t, size_t> sz_mat = matrix_size(mat);
  numRows = sz_mat.first; 
  numCols = sz_mat.second; 

  data = std::vector<std::vector<T>>(numRows, std::vector<T>(numCols));
  
  for(size_t row = 0; row <= numRows-1; row++) { 
    for(size_t col = 0; col <= numCols-1; col++) {
      data[row][col] = mat[row][col];    
    }
  }
}

template<typename T>
void matrix_fill(Matrix<T> &mat, const T& val) { 
  std::pair<size_t, size_t> sz_mat = matrix_size(mat);

  const size_t& numRows = sz_mat.first; 
  const size_t& numCols = sz_mat.second;  

  for(size_t row = 0; row <= numRows-1; row++) { 
    for(size_t col = 0; col <= numCols-1; col++) {
      mat.data[row][col] = val;
    }
  }
}

template<typename T> 
void matrix_add(Matrix<T> &mat, const Matrix<T>& add_mat) { 
  const std::pair<size_t, size_t> & sz_mat = matrix_size(mat);
  const std::pair<size_t, size_t> & sz_add_mat = matrix_size(add_mat);

  if (sz_mat.first != sz_add_mat.first) return; 
  if (sz_mat.second != sz_add_mat.second) return;

  for(size_t row = 0; row <= sz_mat.first-1; row++) { 
    for(size_t col = 0; col <= sz_mat.second-1; col++) { 
      mat.data[row][col] += (add_mat[row][col]);
    }
  }
}

template<typename T> 
void matrix_subtr(Matrix<T> &mat, const Matrix<T>& subtr_mat) { 
  const std::pair<size_t, size_t> & sz_mat = matrix_size(mat);
  const std::pair<size_t, size_t> & sz_subtr_mat = matrix_size(subtr_mat);  
  
  if (sz_mat.first != sz_subtr_mat.first) return; 
  if (sz_mat.second != sz_subtr_mat.second) return; 

  for(size_t row = 0; row <= sz_mat.first-1; row++) { 
    for(size_t col = 0; col <= sz_mat.second-1; col++) { 
      mat.data[row][col] -= (subtr_mat[row][col]);
    }
  }
}

template<typename T>
void matrix_mul(Matrix<T> &mat, const Matrix<T>& mul_mat) {
  const Matrix<T>& ref(mat);

  const std::pair<size_t, size_t> & sz_mat = matrix_size(mat);
  const std::pair<size_t, size_t> & sz_mul_mat = matrix_size(mul_mat);

  if(sz_mat.second != sz_mul_mat.first) return;

  mat.numRows = sz_mat.first; 
  mat.numCols = sz_mul_mat.second; 
  
  mat.data = std::vector<std::vector<T>>(mat.numRows, std::vector<T>(mat.numCols));

  for(size_t row = 0; row <= mat.numRows-1; row++) { 
    for(size_t col = 0; col <= mat.numCols-1; col++) {
      mat.data[row][col] = 0; 
      for(size_t i = 0; i <= sz_mat.first; i++) { 
        for(size_t j = 0; j <= sz_mat.second; j++) { 
          mat.data[row][col] += (matrix_get(ref, i, j) * matrix_get(mul_mat, j, i));
        }
      }
    }
  }  
}