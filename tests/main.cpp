#include "../lib/fmat.h"
#include <iostream>
#include <cassert>

static int tests_run = 0;
static int tests_passed = 0;

#define RUN_TEST(name) \
  do { \
    tests_run++; \
    if (name()) { tests_passed++; std::cout << "[PASS] " #name "\n"; } \
    else { std::cout << "[FAIL] " #name "\n"; } \
  } while(0)

// --- creation and initial values ---

bool test_create_sets_initial_value() {
  fmat m(3, 4, 7.5f);
  for (uint32_t r = 0; r < 3; r++)
    for (uint32_t c = 0; c < 4; c++)
      if (get(m, r, c) != 7.5f) return false;
  return true;
}

bool test_create_zero_fill() {
  fmat m(5, 5, 0.0f);
  for (uint32_t r = 0; r < 5; r++)
    for (uint32_t c = 0; c < 5; c++)
      if (get(m, r, c) != 0.0f) return false;
  return true;
}

bool test_create_1x1() {
  fmat m(1, 1, 42.0f);
  return get(m, 0, 0) == 42.0f;
}

// --- set / get ---

bool test_set_single_element() {
  fmat m(3, 3, 0.0f);
  set(m, 1, 2, 9.9f);
  return get(m, 1, 2) == 9.9f;
}

bool test_set_does_not_affect_other_elements() {
  fmat m(3, 3, 1.0f);
  set(m, 0, 0, 99.0f);
  for (uint32_t r = 0; r < 3; r++)
    for (uint32_t c = 0; c < 3; c++)
      if (r == 0 && c == 0) { if (get(m, r, c) != 99.0f) return false; }
      else                  { if (get(m, r, c) != 1.0f)  return false; }
  return true;
}

bool test_set_overwrite() {
  fmat m(2, 2, 5.0f);
  set(m, 0, 1, 3.0f);
  set(m, 0, 1, 8.0f);
  return get(m, 0, 1) == 8.0f;
}

bool test_set_all_elements() {
  fmat m(4, 4, 0.0f);
  float val = 0.0f;
  for (uint32_t r = 0; r < 4; r++)
    for (uint32_t c = 0; c < 4; c++)
      set(m, r, c, val++);
  val = 0.0f;
  for (uint32_t r = 0; r < 4; r++)
    for (uint32_t c = 0; c < 4; c++)
      if (get(m, r, c) != val++) return false;
  return true;
}

// --- size() ---

bool test_size_rows_and_cols() {
  fmat m(6, 9, 0.0f);
  return m.rsize == 6 && m.csize == 9;
}

bool test_size_square() {
  fmat m(4, 4, 0.0f);
  return m.rsize == 4 && m.csize == 4;
}

bool test_size_1x1() {
  fmat m(1, 1, 0.0f);
  return m.rsize == 1 && m.csize == 1;
}

bool test_size_non_square() {
  fmat m(2, 10, 0.0f);
  return m.rsize == 2 && m.csize == 10;
}

// --- memory: allocate and destroy multiple matrices ---

bool test_multiple_allocations() {
  // If the destructor leaks, ASan/valgrind will report it.
  for (int i = 0; i < 100; i++) {
    fmat m(50, 50, static_cast<float>(i));
    if (get(m, 0, 0) != static_cast<float>(i)) return false;
  }
  return true;
}

bool test_large_matrix_allocation() {
  fmat m(256, 256, 1.0f);
  return m.rsize == 256 && m.csize == 256 && get(m, 255, 255) == 1.0f;
}

int main() {
  RUN_TEST(test_create_sets_initial_value);
  RUN_TEST(test_create_zero_fill);
  RUN_TEST(test_create_1x1);

  RUN_TEST(test_set_single_element);
  RUN_TEST(test_set_does_not_affect_other_elements);
  RUN_TEST(test_set_overwrite);
  RUN_TEST(test_set_all_elements);

  RUN_TEST(test_size_rows_and_cols);
  RUN_TEST(test_size_square);
  RUN_TEST(test_size_1x1);
  RUN_TEST(test_size_non_square);

  RUN_TEST(test_multiple_allocations);
  RUN_TEST(test_large_matrix_allocation);

  std::cout << "\n" << tests_passed << "/" << tests_run << " tests passed.\n";
  return (tests_passed == tests_run) ? 0 : 1;
}