#include "../lib/matrix.cpp"
#include "../lib/matrix.hpp"
#include <gtest/gtest.h>
#include <random> 

const size_t MAX_ROWS = 10; 
const size_t MAX_COLS = 10; 
const float MIN_ENTRY = -1.0;  
const float MAX_ENTRY = 1.0;

std::random_device rd; 
std::mt19937 gen(rd());
std::uniform_real_distribution<float> random_entries(MIN_ENTRY, MAX_ENTRY);
std::uniform_int_distribution<size_t> random_rows(1, MAX_ROWS); 
std::uniform_int_distribution<size_t> random_cols(1, MAX_COLS);

size_t num_rows = random_rows(gen);
size_t num_cols = random_cols(gen);

void fill_random(Mat &mat) { 
  size_t sz = mat.rows * mat.cols; 
  for(size_t i {0}; i < sz; i++) { 
    mat[i] = random_entries(gen);
  }
}

TEST (matrix, init_matrix_and_populate) {
  Mat mat(num_rows, num_cols); 
  EXPECT_TRUE(mat.rows == num_rows);
  EXPECT_TRUE(mat.cols == num_cols);
}

TEST (matrix, matrix_multiplication_throw_on_bad_sizes) { 
  Mat dst(num_rows, num_cols); 
  Mat a (num_rows, num_cols); fill_random(a);
  Mat b (num_cols, num_rows); fill_random(b);
  EXPECT_FALSE(mat_mul(dst, a, b)) ;
}

TEST (matrix, matrix_multiplication_normal) { 
  Mat dst(num_rows, num_rows); 
  Mat a (num_rows, num_cols); fill_random(a);
  Mat b (num_cols, num_rows); fill_random(b);
  EXPECT_TRUE(mat_mul(dst, a, b));
}

TEST (matrix, matrix_transpose) { 
  Mat mat(num_rows, num_cols);
  Mat dst(num_cols, num_rows);
  fill_random(mat);
  EXPECT_TRUE(mat_tr(dst, mat));
  mat_out(dst);
  mat_out(mat);
}

int main(void) {
  ::testing::InitGoogleTest(); 
  return RUN_ALL_TESTS(); 
}