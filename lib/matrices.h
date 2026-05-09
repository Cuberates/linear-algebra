#include <iostream> 
#include <cassert>

template<typename Data>
class Matrix { 
  public: 
    Matrix(uint32_t numRows, uint32_t numCols, Data value);
    Matrix(const Matrix& mat);
    Matrix(Matrix&& mat);
    ~Matrix();  
    uint32_t getRows() const;
    uint32_t getCols() const; 
    Matrix& operator=(const Matrix& mat); 
    Matrix& operator=(Matrix&& mat);
    Data& operator[](uint32_t row, uint32_t col);
    const Data& operator[](uint32_t row, uint32_t col) const;
    Matrix& operator+=(const Matrix& mat);
    Matrix operator+(const Matrix& mat) const;
    Matrix& operator-=(const Matrix& mat);
    Matrix operator-(const Matrix& mat) const;  
    Matrix& operator*=(const Matrix& mat);
    Matrix operator*(const Matrix& mat) const;  
  private: 
    uint32_t numRows; 
    uint32_t numCols; 
    Data** data; 
};

template<typename Data> 
Matrix<Data>::Matrix(uint32_t numRows, uint32_t numCols, Data value) : numRows(numRows), numCols(numCols) { 
  data = new Data*[numRows]; 
  for(uint32_t r = 0; r < numRows; r++) { 
    data[r] = new Data[numCols]; 
    for(uint32_t c = 0; c < numCols; c++) { 
      data[r][c] = value;
    }
  }
}

template<typename Data> 
Matrix<Data>::Matrix(const Matrix& mat) : numRows(mat.numRows), numCols(mat.numCols) {
  data = new Data*[numRows]; 
  for(uint32_t r = 0; r < numRows; r++) { 
    data[r] = new Data[numCols]; 
    for(uint32_t c = 0; c < numCols; c++) { 
      data[r][c] = mat.data[r][c];
    }
  }
}

template<typename Data>
Matrix<Data>::Matrix(Matrix&& mat) : numRows(mat.numRows), numCols(mat.numCols), data(mat.data) { 
  mat.data = nullptr; 
}

template<typename Data>
Matrix<Data>::~Matrix() { 
  if (data != nullptr) { 
    for(uint32_t r = 0; r < numRows; r++) { 
      delete[] data[r];
    }
    delete[] data;
  }
}

template<typename Data> 
Matrix<Data>& Matrix<Data>::operator=(const Matrix& mat) { 
  if (this == mat) return *this;

  if (mat.numCols == this->numCols && mat.numRows == this->numRows) { 
    for(uint32_t r = 0; r < numRows; r++) { 
      for(uint32_t c = 0; c < numCols; c++) { 
        data[r][c] = mat[r][c];
      }
    }
    return *this;
  }

  for(uint32_t r = 0; r < numRows; r++) { 
    delete[] data[r];
  }
  delete[] data;

  numRows = mat.getRows();
  numCols = mat.getCols(); 

  data = new Data*[numRows];
  for(uint32_t r = 0; r < numRows; r++) { 
    data[r] = new Data[numCols];
    for(uint32_t c = 0; c < numCols; c++) { 
      data[r][c] = mat[r][c];
    }
  }
}

