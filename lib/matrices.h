#include <iostream> 
#include <cassert>

template<typename Data>
class Matrix { 
  public: 
    Matrix(uint32_t rsize, uint32_t csize, Data val);
    Matrix(const Matrix& mat);
    Matrix(Matrix&& mat);
    ~Matrix();   
    friend void set(Matrix<Data> & mat, uint32_t row, uint32_t col, Data val); 
    Data & get(uint32_t row, uint32_t col) const;  
  private: 
    uint32_t rsize; 
    uint32_t csize; 
    Data** data; 
};
template<typename Data> 
Matrix<Data>::Matrix(uint32_t rsize, uint32_t csize, Data val) : rsize(rsize), csize(csize) { 
  data = new Data*[this->rsize];
  for(uint32_t r = 0; r <= this->rsize-1; r++) { 
    data[r] = new Data[this->csize];
    for(uint32_t c = 0; c <= this->csize-1; c++) { 
      data[r][c] = val;
    }
  }
}
template<typename Data> 
Matrix<Data>::Matrix(const Matrix & mat) { 
  data = new Data*[this->rsize];
  for(uint32_t r = 0; r <= this->rsize-1; r++) { 
    data[r] = new Data[this->csize];
    for(uint32_t c = 0; c <= this->csize-1; c++) { 
      data[r][c] = mat[r][c];
    }
  }
}

template<typename Data> 
Matrix<Data>::~Matrix() { 
  for(uint32_t r = 0; r <= this->rsize-1; r++) { 
    delete [] data[r];
  }
  delete [] data;
}