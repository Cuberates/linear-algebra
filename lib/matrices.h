#include <iostream> 

/*
  Define a Matrix structure that can hold any type of data. 
*/

template<typename Data>
class Matrix { 
  public: 
    Matrix(uint32_t numRows, uint32_t numCols, Data value);
    Matrix(const Matrix& mat);
    Matrix(Matrix&& mat) noexcept;
    ~Matrix();  
    Matrix& operator=(const Matrix& mat); 
    Matrix& operator=(Matrix&& mat) noexcept;
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

/*
  Implement the Matrix structure, along with some important arithmetic operations. 
  Operations to be implemented include: 
    - Copy constructor
    - Move constructor
    - Destructor
    - Copy assignment operator
    - Move assignment operator
    - Element access operator
    - Addition and subtraction operators (both in-place and returning a new matrix)
    - Multiplication operator (both in-place and returning a new matrix)
*/

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
Matrix<Data>::Matrix(Matrix&& mat) noexcept : numRows(mat.numRows), numCols(mat.numCols), data(mat.data) { 
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
