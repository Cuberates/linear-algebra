#include <gtest/gtest.h>
#include "../lib/Matrix.hpp"

TEST(MATRIX, INITIALIZE_EMPTY_MATRIX) { 
  Matrix<float_t> empty_matrix;
  EXPECT_EQ(0, empty_matrix.numCols());
  EXPECT_EQ(0, empty_matrix.numRows());
}

TEST(MATRIX, INITIALIZE_SQUARE_MATRIX) { 
  std::size_t n = 10; 
  Matrix<float_t> square_matrix(static_cast<size_t>(n), static_cast<size_t>(n));
  EXPECT_EQ(n, square_matrix.numCols());
  EXPECT_EQ(n, square_matrix.numRows());
  EXPECT_TRUE(square_matrix.numCols() == square_matrix.numRows());
}

TEST(MATRIX, INITIALIZE_NORMAL_MATRIX) { 
  std::size_t rows = 3, cols = 5;
  Matrix<float_t> matrix(rows, cols);
  EXPECT_EQ(rows, matrix.numRows());
  EXPECT_EQ(cols, matrix.numCols());
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}