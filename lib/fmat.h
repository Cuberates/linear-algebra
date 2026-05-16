#include <iostream> 
#include <cassert>

class fmat {
  public:
  size_t rsize; 
  size_t csize;
  float** mat;
  fmat(size_t rsize, size_t csize, const float& val = 0);
  ~fmat();
  friend float get(const fmat & mat, uint32_t r, uint32_t c);
  friend void set(fmat & mat, uint32_t r, uint32_t c, const float& val);
  friend void out(const fmat & mat);
};

float get(const fmat & mat, uint32_t r, uint32_t c) { 
  return mat.mat[r][c];
}

void set(fmat & mat, uint32_t r, uint32_t c, const float& val) { 
  mat.mat[r][c] = val;
}

fmat::fmat(size_t rsize, size_t csize, const float& val) : rsize(rsize), csize(csize) {
  mat = new float*[rsize];
  for(size_t r = 0; r <= rsize-1; r++) { 
    mat[r] = new float[csize];
    for(size_t c = 0; c <= csize-1; c++) {
      mat[r][c] = val;
    }
  }
}

fmat::~fmat() {
  for(size_t r = 0; r <= rsize-1; r++) { 
    delete [] mat[r];
  }
  delete[] mat;
}

void out(const fmat& mat) { 
  for(size_t r = 0; r <= mat.rsize - 1; r++) { 
    for(size_t c = 0; c <= mat.csize - 1; c++) { 
      std::cout << mat.mat[r][c] << " ";
    }
    std::cout << "\n";
  }
}

fmat add(const fmat & m1, const fmat & m2);
fmat subtr(const fmat & m1, const fmat & m2);
fmat mul(const fmat & m1, const fmat & m2);

fmat add(const fmat & m1, const fmat & m2) { 
  const size_t m1_sr = m1.rsize; 
  const size_t m1_sc = m1.csize; 
  const size_t m2_sr = m2.rsize; 
  const size_t m2_sc = m2.csize;
  
  if (m1_sr == m2_sr && m1_sc == m2_sc) { 
    fmat res = fmat(m1_sr, m1_sc, 0);
    for(size_t r = 0; r <= m1_sr-1; r++) { 
      for(size_t c = 0; c <= m1_sc-1; c++) {
        const float &a = get(m1, r, c);
        const float &b = get(m2, r, c);
        set(res, r, c, a + b);
      }
    }
  }
  return fmat(0, 0, 0);
}

fmat subtr(const fmat &m1, const fmat &m2) { 
  const size_t m1_sr = m1.rsize; 
  const size_t m1_sc = m1.csize; 
  const size_t m2_sr = m2.rsize; 
  const size_t m2_sc = m2.csize;
  
  if (m1_sr == m2_sr && m1_sc == m2_sc) { 
    fmat res = fmat(m1_sr, m1_sc, 0);
    for(size_t r = 0; r <= m1_sr-1; r++) { 
      for(size_t c = 0; c <= m1_sc-1; c++) { 
        const float &a = get(m1, r, c);
        const float &b = get(m2, r, c);
        set(res, r, c, a - b);
      }
    }
  }
  return fmat(0, 0, 0);
}