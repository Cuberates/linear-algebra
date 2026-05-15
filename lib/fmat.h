#include <iostream> 
#include <cassert>

class dim { 
  public:
  size_t row; 
  size_t col;
  dim(size_t row, size_t col) : row(row), col(col) {}
  friend void out(const dim & dim) { std::cout << dim.row << " " << dim.col << "\n";}
};

class fmat {
  dim sz;   
  float** mat;
public:
  fmat(size_t rsize, size_t csize, const float& val);
  ~fmat();
  const dim & size ();
  friend float get(const fmat & mat, uint32_t r, uint32_t c);
  friend void set(fmat & mat, uint32_t r, uint32_t c, const float& val);
  friend void out(const fmat & mat);
};

const dim& fmat::size() { 
  return sz;
}

float get(const fmat & mat, uint32_t r, uint32_t c) { 
  return mat.mat[r][c];
}

void set(fmat & mat, uint32_t r, uint32_t c, const float& val) { 
  mat.mat[r][c] = val;
}

fmat::fmat(size_t rsize, size_t csize, const float& val) : sz(rsize, csize) {
  mat = new float*[sz.row];
  for(size_t r = 0; r <= rsize-1; r++) { 
    mat[r] = new float[sz.col];
    for(size_t c = 0; c <= csize-1; c++) {
      mat[r][c] = val;
    }
  }
}

fmat::~fmat() {
  for(size_t r = 0; r < sz.row; r++) {
    delete[] mat[r];
  }
  delete[] mat;
}

void out(const fmat& mat) { 
  for(size_t r = 0; r < mat.sz.row; r++) { 
    for(size_t c = 0; c < mat.sz.col; c++) { 
      std::cout << get(mat, r, c) << " ";
    }
    std::cout << "\n";
  }
}

