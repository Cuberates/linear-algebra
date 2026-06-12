#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <cmath>

#include "matrix.hpp"

using Matrix = std::vector<std::vector<float>>;

Matrix linalg::mul(const Matrix& mat1, const Matrix& mat2) {
  size_t n = mat1.size();
  size_t m = mat2[0].size();
  size_t p = mat2.size();
  Matrix result(n, std::vector<float>(m, 0.0f));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      for (size_t k = 0; k < p; ++k) {
        result[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
  return result;
}

Matrix linalg::add(const Matrix& mat1, const Matrix& mat2) { 
  size_t n = mat1.size();
  size_t m = mat1[0].size();
  Matrix result(n, std::vector<float>(m, 0.0f));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      result[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
  return result;
}

Matrix linalg::tr(const Matrix& mat1) {
  size_t n = mat1.size();
  size_t m = mat1[0].size();
  Matrix result(m, std::vector<float>(n, 0.0f));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      result[j][i] = mat1[i][j];
    }
  }
  return result;
}

Matrix linalg::diag(const Matrix& mat) { 
  size_t n = mat.size();
  size_t m = mat[0].size();
  Matrix result(n, std::vector<float>(m, 0.0f));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      if (i == j) {
        result[i][j] = mat[i][j];
      }
    }
  }
  return result;
}

Matrix linalg::identity(size_t n) {
  Matrix result(n, std::vector<float>(n, 0.0f));
  for (size_t i = 0; i < n; ++i) {
    result[i][i] = 1.0f;
  }
  return result;
}

Matrix linalg::zeros(size_t n, size_t m) {
  return Matrix(n, std::vector<float>(m, 0.0f));
}
Matrix linalg::ones(size_t n, size_t m) {
  return Matrix(n, std::vector<float>(m, 1.0f));
}

Matrix linalg::rand(size_t n, size_t m) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);
  Matrix result(n, std::vector<float>(m, 0.0f));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      result[i][j] = dis(gen);
    }
  }
  return result;
}

Matrix linalg::randn(size_t n, size_t m) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> dis(0.0, 1.0);
  Matrix result(n, std::vector<float>(m, 0.0f));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      result[i][j] = dis(gen);
    }
  }
  return result;
}