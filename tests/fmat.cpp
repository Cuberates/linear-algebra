#include "../lib/fmat.h"
#include <iostream>

static int tests_run = 0;
static int tests_passed = 0;

#define RUN_TEST(name) \
  do { \
    tests_run++; \
    if (name()) { tests_passed++; std::cout << "[PASS] " #name "\n"; } \
    else { std::cout << "[FAIL] " #name "\n"; } \
  } while(0)

bool same_matrix(const fmat& a, const fmat& b) {
  if (a.rsize != b.rsize || a.csize != b.csize) {
    return false;
  }

  for (size_t r = 0; r < a.rsize; r++) {
    for (size_t c = 0; c < a.csize; c++) {
      if (get(a, r, c) != get(b, r, c)) {
        return false;
      }
    }
  }

  return true;
}

bool test_add_same_shape_values() {
  fmat a(2, 2, 0.0f);
  fmat b(2, 2, 0.0f);

  set(a, 0, 0, 1.0f); set(a, 0, 1, 2.0f);
  set(a, 1, 0, 3.0f); set(a, 1, 1, 4.0f);

  set(b, 0, 0, 10.0f); set(b, 0, 1, 20.0f);
  set(b, 1, 0, 30.0f); set(b, 1, 1, 40.0f);

  fmat expected(2, 2, 0.0f);
  set(expected, 0, 0, 11.0f); set(expected, 0, 1, 22.0f);
  set(expected, 1, 0, 33.0f); set(expected, 1, 1, 44.0f);

  fmat result = add(a, b);
  return same_matrix(result, expected);
}

bool test_add_mismatched_shape_returns_empty() {
  fmat a(2, 3, 1.0f);
  fmat b(3, 2, 1.0f);

  fmat result = add(a, b);
  return result.rsize == 0 && result.csize == 0;
}

bool test_add_does_not_modify_operands() {
  fmat a(2, 2, 1.0f);
  fmat b(2, 2, 2.0f);

  fmat a_before(2, 2, 1.0f);
  fmat b_before(2, 2, 2.0f);

  (void)add(a, b);

  return same_matrix(a, a_before) && same_matrix(b, b_before);
}

int main() {
  RUN_TEST(test_add_same_shape_values);
  RUN_TEST(test_add_mismatched_shape_returns_empty);
  RUN_TEST(test_add_does_not_modify_operands);

  std::cout << "\n" << tests_passed << "/" << tests_run << " arithmetic tests passed.\n";
  return (tests_passed == tests_run) ? 0 : 1;
}
