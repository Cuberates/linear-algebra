#include "../lib/matrix.h"
#include <cassert>
#include <iostream>

static void test_constructor_fill_value() {
	Matrix<int> mat(2, 3, 7);
	auto sz = matrix_size(mat);
	assert(sz.first == 2);
	assert(sz.second == 3);
	for (size_t r = 0; r < 2; r++) {
		for (size_t c = 0; c < 3; c++) {
			assert(mat[r][c] == 7);
		}
	}
}

static void test_constructor_from_2d_array() {
	Matrix<int> mat(2, 2, std::vector<std::vector<int>>{{1, 2}, {3, 4}});
	assert(mat[0][0] == 1);
	assert(mat[0][1] == 2);
	assert(mat[1][0] == 3);
	assert(mat[1][1] == 4);
}

static void test_copy_constructor() {
	Matrix<int> original(2, 2, std::vector<std::vector<int>>{{5, 6}, {7, 8}});
	Matrix<int> copy(original);
	assert(copy[0][0] == 5);
	assert(copy[0][1] == 6);
	assert(copy[1][0] == 7);
	assert(copy[1][1] == 8);
}

static void test_matrix_set_and_operator_access() {
	Matrix<int> mat(2, 2, 0);
	matrix_set(mat, 0, 1, 9);
	mat[1][0] = 4;
	assert(mat[0][1] == 9);
	assert(mat[1][0] == 4);
}

static void test_matrix_fill() {
	Matrix<int> mat(3, 2, 0);
	matrix_fill(mat, -3);
	for (size_t r = 0; r < 3; r++) {
		for (size_t c = 0; c < 2; c++) {
			assert(mat[r][c] == -3);
		}
	}
}

static void test_matrix_add() {
	Matrix<int> a(2, 2, std::vector<std::vector<int>>{{1, 2}, {3, 4}});
	Matrix<int> b(2, 2, std::vector<std::vector<int>>{{5, 6}, {7, 8}});
	matrix_add(a, b);
	assert(a[0][0] == 6);
	assert(a[0][1] == 8);
	assert(a[1][0] == 10);
	assert(a[1][1] == 12);
}

static void test_matrix_subtr() {
	Matrix<int> a(2, 2, std::vector<std::vector<int>>{{10, 9}, {8, 7}});
	Matrix<int> b(2, 2, std::vector<std::vector<int>>{{1, 2}, {3, 4}});
	matrix_subtr(a, b);
	assert(a[0][0] == 9);
	assert(a[0][1] == 7);
	assert(a[1][0] == 5);
	assert(a[1][1] == 3);
}

static void test_matrix_mul() {
	Matrix<int> a(2, 3, std::vector<std::vector<int>>{{1, 2, 3}, {4, 5, 6}});
	Matrix<int> b(3, 2, std::vector<std::vector<int>>{{7, 8}, {9, 10}, {11, 12}});
	matrix_mul(a, b);

	auto sz = matrix_size(a);
	assert(sz.first == 2);
	assert(sz.second == 2);
	assert(a[0][0] == 58);
	assert(a[0][1] == 64);
	assert(a[1][0] == 139);
	assert(a[1][1] == 154);
}

static void test_dimension_guard_no_change() {
	Matrix<int> add_lhs(2, 2, std::vector<std::vector<int>>{{1, 1}, {1, 1}});
	Matrix<int> add_rhs(1, 2, std::vector<std::vector<int>>{{2, 2}});
	matrix_add(add_lhs, add_rhs);
	assert(add_lhs[0][0] == 1 && add_lhs[1][1] == 1);

	Matrix<int> mul_lhs(2, 2, std::vector<std::vector<int>>{{1, 2}, {3, 4}});
	Matrix<int> mul_rhs(3, 1, std::vector<std::vector<int>>{{1}, {2}, {3}});
	matrix_mul(mul_lhs, mul_rhs);
	auto sz = matrix_size(mul_lhs);
	assert(sz.first == 2);
	assert(sz.second == 2);
	assert(mul_lhs[0][0] == 1);
	assert(mul_lhs[0][1] == 2);
	assert(mul_lhs[1][0] == 3);
	assert(mul_lhs[1][1] == 4);
}

int main(void) { 
	test_constructor_fill_value();
	test_constructor_from_2d_array();
	test_copy_constructor();
	test_matrix_set_and_operator_access();
	test_matrix_fill();
	test_matrix_add();
	test_matrix_subtr();
	test_matrix_mul();
	test_dimension_guard_no_change();

	std::cout << "All matrix tests passed.\n";
	return 0;
}