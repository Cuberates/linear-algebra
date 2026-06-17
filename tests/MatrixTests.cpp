#include <gtest/gtest.h>
#include "../lib/Matrix.hpp"
#include "../src/Matrix.cpp"

TEST(MATRIX, INITIALIZE_EMPTY_MATRIX) { 
  Matrix<float_t> m;
  EXPECT_EQ(static_cast<size_t>(0), m.numCols());
  EXPECT_EQ(static_cast<size_t>(0), m.numRows());
}

TEST(MATRIX, INITIALIZE_SQUARE_MATRIX) { 
  std::size_t n = 10; 
  Matrix<float_t> m(static_cast<size_t>(n), static_cast<size_t>(n));
  EXPECT_EQ(n, m.numCols());
  EXPECT_EQ(n, m.numRows());
  EXPECT_TRUE(m.numCols() == m.numRows());
}

TEST(MATRIX, INITIALIZE_NORMAL_MATRIX) { 
  std::size_t rows = 3, cols = 5;
  Matrix<float_t> m(rows, cols);
  EXPECT_EQ(rows, m.numRows());
  EXPECT_EQ(cols, m.numCols());
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}