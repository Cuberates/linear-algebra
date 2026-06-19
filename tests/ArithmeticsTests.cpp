#include <gtest/gtest.h>
#include <limits>
#include "../lib/Matrix.hpp"
#include "../src/Matrix.cpp"
#include "../src/Arithmetics.cpp"

TEST(MATRIX_OPERATOR, ADD_MATRIX_SAME_SIZES) { 
  std::vector<std::vector<float_t>> v = { 
    {1, 2, 3}, 
    {4, 5, 6}, 
    {7, 8, 9},
  }; 
  Matrix<float_t> a(v), b(v); 
  Matrix<float_t> dst(a.numRows(), a.numCols());
  EXPECT_TRUE(Mat::add(dst, a, b));
  for(size_t r = 0; r < dst.numRows(); ++r) { 
    for(size_t c = 0; c < dst.numCols(); ++c) { 
      EXPECT_EQ(a(r, c) + b(r, c), dst(r, c));
    }
  }
}

TEST(MATRIX_OPERATOR, ADD_MATRIX_DIFF_SIZES) { 
  std::vector<std::vector<float_t>> v = { 
    {1, 2, 3}, 
    {4, 5, 6}, 
    {7, 8, 9},
  }; 
  std::vector<std::vector<float_t>> w = { 
    {1, 2}, 
    {3, 4},
  };
  Matrix<float_t> a(v), b(w);
  Matrix<float_t> dst(a.numRows(), a.numCols());
  EXPECT_FALSE(Mat::add(dst, a, b)); 
}

TEST(MATRIX_OPERATOR, ADD_MATRIX_DIFF_DST_SIZES) { 
  std::vector<std::vector<float_t>> v = { 
    {1, 2, 3}, 
    {4, 5, 6}, 
    {7, 8, 9},
  }; 
  Matrix<float_t> a(v), b(v);
  Matrix<float_t> dst(a.numRows()+1, a.numCols()+1);
  EXPECT_FALSE(Mat::add(dst, a, b)); 
}

TEST(MATRIX_OPERATOR, ADD_MATRIX_EMPTY_MATRICES) {
  Matrix<float_t> a;
  Matrix<float_t> b;
  Matrix<float_t> dst;

  EXPECT_FALSE(Mat::add(dst, a, b));
}

TEST(MATRIX_OPERATOR, ADD_MATRIX_LARGE_NUMBERS) {
  const float_t large = std::numeric_limits<float_t>::max();
  std::vector<std::vector<float_t>> v = {
    {large, large},
    {large, large},
  };

  Matrix<float_t> a(v), b(v);
  Matrix<float_t> dst(a.numRows(), a.numCols());
  EXPECT_FALSE(Mat::add(dst, a, b));
}

TEST(MATRIX_OPERATOR, SUBTRACT_MATRIX_SAME_SIZES) { 
  std::vector<std::vector<float_t>> v = { 
    {1, 2, 3}, 
    {4, 5, 6}, 
    {7, 8, 9},
  }; 
  Matrix<float_t> a(v), b(v); 
  Matrix<float_t> dst(a.numRows(), a.numCols());
  EXPECT_TRUE(Mat::subtract(dst, a, b));
  for(size_t r = 0; r < dst.numRows(); ++r) { 
    for(size_t c = 0; c < dst.numCols(); ++c) { 
      EXPECT_EQ(a(r, c) - b(r, c), dst(r, c));
    }
  }   
} 

TEST(MATRIX_OPERATOR, SUBTRACT_MATRIX_DIFF_SIZES) { 
  std::vector<std::vector<float_t>> v = { 
    {1, 2, 3}, 
    {4, 5, 6}, 
    {7, 8, 9},
  }; 
  std::vector<std::vector<float_t>> w = { 
    {1, 2}, 
    {3, 4},
  };
  Matrix<float_t> a(v), b(w);
  Matrix<float_t> dst(a.numRows(), a.numCols());
  EXPECT_FALSE(Mat::subtract(dst, a, b));  
}

TEST(MATRIX_OPERATOR, SUBTRACT_MATRIX_DIFF_DST_SIZES) { 
  std::vector<std::vector<float_t>> v = { 
    {1, 2, 3}, 
    {4, 5, 6}, 
    {7, 8, 9},
  }; 
  Matrix<float_t> a(v), b(v);
  Matrix<float_t> dst(a.numRows()+1, a.numCols()+1);
  EXPECT_FALSE(Mat::subtract(dst, a, b)); 
}

TEST(MATRIX_OPERATOR, SUBTRACT_MATRIX_EMPTY_MATRICES) {
  Matrix<float_t> a;
  Matrix<float_t> b;
  Matrix<float_t> dst;

  EXPECT_FALSE(Mat::subtract(dst, a, b));
}

TEST(MATRIX_OPERATOR, SUBTRACT_MATRIX_LARGE_NUMBERS) {
  const float_t large = std::numeric_limits<float_t>::max();
  std::vector<std::vector<float_t>> va = {
    {large, large},
    {large, large},
  };
  std::vector<std::vector<float_t>> vb = {
    {-large, -large},
    {-large, -large},
  };

  Matrix<float_t> a(va), b(vb);
  Matrix<float_t> dst(a.numRows(), a.numCols());
  EXPECT_FALSE(Mat::subtract(dst, a, b));
}

TEST(MATRIX_OPERATOR, SCALE_MATRIX_NORMAL) {
  std::vector<std::vector<float_t>> v = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };
  Matrix<float_t> dst(v);
  const float_t scalar = 3.0f;

  EXPECT_TRUE(Mat::scale(dst, scalar));
  for(size_t r = 0; r < dst.numRows(); ++r) {
    for(size_t c = 0; c < dst.numCols(); ++c) {
      EXPECT_EQ(v[r][c] * scalar, dst(r, c));
    }
  }
}

TEST(MATRIX_OPERATOR, SCALE_MATRIX_WITH_ZERO) {
  std::vector<std::vector<float_t>> v = {
    {1, 2, 3},
    {4, 5, 6},
  };
  Matrix<float_t> dst(v);

  EXPECT_TRUE(Mat::scale(dst, 0.0f));
  for(size_t r = 0; r < dst.numRows(); ++r) {
    for(size_t c = 0; c < dst.numCols(); ++c) {
      EXPECT_EQ(0.0f, dst(r, c));
    }
  }
}

TEST(MATRIX_OPERATOR, SCALE_MATRIX_EMPTY_MATRIX) {
  Matrix<float_t> dst;
  EXPECT_FALSE(Mat::scale(dst, 2.0f));
}

TEST(MATRIX_OPERATOR, SCALE_MATRIX_LARGE_NUMBERS) {
  const float_t large = std::numeric_limits<float_t>::max();
  std::vector<std::vector<float_t>> v = {
    {large, large},
    {large, large},
  };
  Matrix<float_t> dst(v);

  EXPECT_FALSE(Mat::scale(dst, 2.0f));
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
