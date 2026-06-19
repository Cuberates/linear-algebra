#include <gtest/gtest.h>
#include "../lib/Matrix.hpp"
#include "../lib/Matrix.cpp"

TEST(MATRIX_INIT, INIT_EMPTY_MATRIX) { 
  Matrix<float_t> m;
  EXPECT_EQ(static_cast<size_t>(0), m.numCols());
  EXPECT_EQ(static_cast<size_t>(0), m.numRows());
}

TEST(MATRIX_INIT, INIT_SQUARE_MATRIX) { 
  std::size_t n = 10; 
  Matrix<float_t> m(static_cast<size_t>(n), static_cast<size_t>(n));
  EXPECT_EQ(n, m.numCols());
  EXPECT_EQ(n, m.numRows());
  EXPECT_EQ(m.numCols(), m.numRows()); 
}

TEST(MATRIX_INIT, INIT_NORMAL_MATRIX) { 
  std::size_t rows = 3, cols = 5;
  Matrix<float_t> m(rows, cols);
  EXPECT_EQ(rows, m.numRows());
  EXPECT_EQ(cols, m.numCols());
}

TEST(MATRIX_INIT, INIT_FROM_VECTOR) { 
  std::vector<std::vector<float_t>> v = { 
    {1, 2, 3}, 
    {4, 5, 6}, 
    {7, 8, 9},
  };
  Matrix<float_t> m(v); 
  EXPECT_EQ(v.size(), m.numRows());
  EXPECT_EQ(v[0].size(), m.numCols());
  for (size_t r = 0; r < m.numRows(); ++r) { 
    for (size_t c = 0; c < m.numCols(); ++c) { 
      EXPECT_EQ(v[r][c], m(r, c));
    }
  }
}

TEST(MATRIX_OPERATOR, ASSIGN_VALUE) { 
  std::vector<std::vector<float_t>> v = { 
    {1, 2, 3}, 
    {4, 5, 6}, 
    {7, 8, 9},
  }; 

  Matrix<float_t> m(v);  
  for(size_t r = 0; r < m.numRows(); ++r) { 
    for(size_t c = 0; c < m.numCols(); ++c) { 
      m(r, c) = (r*c);
      EXPECT_EQ(r*c, m(r, c));
    }
  }
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
