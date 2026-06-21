#include "Matrix.hpp"
#include <type_traits>

namespace Mat {
  template<typename T>
  [[nodiscard]] 
  bool same_size(const Matrix<T>& A, const Matrix<T>& B); 
  template<typename T>
  bool add_to(Matrix<T>& dst, const Matrix<T>& A, const Matrix<T>& B); 
  template<typename T> 
  bool add(Matrix<T>& dst, const Matrix<T>& A); 
  template<typename T>
  bool subtract_to(Matrix<T>& dst, const Matrix<T>& A, const Matrix<T>& B);
  template<typename T>
  bool subtract(Matrix<T>& dst, const Matrix<T>& A); 
  template<typename T> 
  bool scale(Matrix<T> &dst, const T& scalar);
  template<typename T> 
  bool mul(Matrix<T> &dst, const Matrix<T>& A, const Matrix<T>& B); 
}

template<typename T>
bool Mat::same_size(const Matrix<T>& A, const Matrix<T>& B) { 
  if (A.numRows() != B.numRows()) return false;
  if (A.numCols() != B.numCols()) return false;
  return true; 
}

template<typename T> 
bool Mat::add_to(Matrix<T>& dst, const Matrix<T>& A, const Matrix<T>& B) {  
  if (!Mat::same_size(A, B)) return false; 
  if (!Mat::same_size(A, dst)) return false; 
  if (dst.numRows() == 0 && dst.numCols() == 0) return false;
 
  for(size_t row = 0; row < dst.numRows(); ++row) { 
    for(size_t col = 0; col < dst.numCols(); ++col) { 
      const T value = A(row, col) + B(row, col);
      if constexpr (std::is_floating_point_v<T>) {
        if (!std::isfinite(value)) return false;
      }
      dst(row, col) = std::move(value); 
    }
  }
  return true;
}

template<typename T>
bool Mat::add(Matrix<T>& dst, const Matrix<T>& A) {
  if (!Mat::same_size(dst, A)) return false;
  if (dst.numRows() == 0 && dst.numCols() == 0) return false;

  for(size_t row = 0; row < dst.numRows(); ++row) { 
    for(size_t col = 0; col < dst.numCols(); ++col) { 
      const T value = dst(row, col) + A(row, col);
      if constexpr(std::is_floating_point_v<T>) { 
        if (!std::isfinite(value)) return false; 
      }
      dst(row, col) = std::move(value);
    }
  }
  return true;
}

template<typename T> 
bool Mat::subtract_to(Matrix<T>& dst, const Matrix<T>& A, const Matrix<T> &B) { 
  if (!Mat::same_size(A, B)) return false; 
  if (!Mat::same_size(dst, A)) return false; 
  if (dst.numRows() == 0 && dst.numCols() == 0) return false;
  
  for (size_t row = 0; row < B.numRows(); ++row) { 
    for (size_t col = 0; col < B.numCols(); ++col) { 
      const T value = A(row, col) - B(row, col);
      if constexpr (std::is_floating_point_v<T>) {
        if (!std::isfinite(value)) return false;
      }
      dst(row, col) = std::move(value);
    }
  }
  return true; 
}

template<typename T> 
bool Mat::subtract(Matrix<T>& dst, const Matrix<T>& A) { 
  if (!Mat::same_size(dst, A)) return false;
  if (dst.numRows() == 0 && dst.numCols() == 0) return false;

  for(size_t row = 0; row < dst.numRows(); ++row) { 
    for(size_t col = 0; col < dst.numCols(); ++col) { 
      const T value = dst(row, col) - A(row, col);
      if constexpr(std::is_floating_point_v<T>) { 
        if (!std::isfinite(value)) return false; 
      }
      dst(row, col) = std::move(value);
    }
  }
  return true;
}

template<typename T> 
bool Mat::scale(Matrix<T> &dst, const T& scalar) {
  if (dst.numRows() == 0 && dst.numCols() == 0) return false; 
  
  for(size_t row = 0; row < dst.numRows(); ++row) { 
    for(size_t col = 0; col < dst.numCols(); ++col) { 
      const T value = scalar * dst(row, col);
      if constexpr (std::is_floating_point_v<T>) { 
        if (!std::isfinite(value)) return false; 
      }
      dst(row, col) = std::move(value);
    } 
  }
  return true; 
}

template<typename T> 
bool Mat::mul(Matrix<T> &dst, const Matrix<T>& A, const Matrix<T>& B) {
  if (A.numCols() != B.numRows()) return false;  
  if (dst.numRows() != A.numRows()) return false; 
  if (dst.numCols() != B.numCols()) return false; 

  for(size_t row = 0; row < dst.numRows(); ++row) { 
    for(size_t col = 0; col < dst.numCols(); ++col) { 
      T sum = 0; 
      for(size_t k = 0; k < A.numCols(); ++k) { 
        sum = sum + (A(row, k) * B(k, col));
      }
      dst(row, col) = std::move(sum);
    }
  }
  return true;
}