#include <iostream> 
#include <vector>

template<typename T>
class Matrix { 
  public: 
  Matrix(size_t numRows, size_t numCols, const T& data);  
  Matrix(const Matrix<T>& copy);
  ~Matrix();

  friend void matrix_fill(const T& data);
  friend std::pair<size_t, size_t> matrix_size(const Matrix<T>& mat);
  friend void matrix_add(Matrix<T>& dst, const Matrix<T>& add_mat);
  friend void matrix_subtr(Matrix<T>& dst, const Matrix<T>& subtr_mat);
  friend void matrix_mul(Matrix<T>& dst, const Matrix<T>& mul_mat);

  private:   
  size_t numRows; 
  size_t numCols; 
  std::vector<T> data; 
};

template<typename T> 
Matrix<T>::Matrix(size_t numRows, size_t numCols, const T& data) : 
  numRows(numRows), numCols(numCols), data(std::vector<std::vector<T>>(numRows, std::vector<T>(numCols, T))) {}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& mat_copy) { 
  std::pair<size_t, size_t> sz_mat_copy; 
  
}


