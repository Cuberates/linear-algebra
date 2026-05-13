#include <iostream> 
#include <cassert>

/*  
  !! Refactorization
  In set(), passing in Data by value is going to copy the Data.
    => Think of a way to optimize this further, preferably that minimizes (or eliminate) copying.
*/

template<typename Data>
class Matrix { 
  public: 
    Matrix(uint32_t szRow, uint32_t szCol, Data value);
    Matrix(const Matrix& mat);
    Matrix(Matrix&& mat);
    ~Matrix();  
    friend uint32_t szRow();
    friend uint32_t szCol();
    void set(Matrix<Data> & mat, uint32_t row, uint32_t col, Data val); 
    Data & get(uint32_t row, uint32_t col) const;  
  private: 
    uint32_t szRow; 
    uint32_t szCol; 
    Data** data; 
};
