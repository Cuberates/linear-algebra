#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
  
class Matrix {
  private: 
  size_t rows; 
  size_t cols;
  std::vector<float> data; 
    
  public:
  inline size_t row_size();   
  inline size_t col_size(); 

  inline float & operator() (size_t row_idx, size_t col_idx); 
  inline float operator() (size_t row_idx, size_t col_idx) const;       
};


#endif
