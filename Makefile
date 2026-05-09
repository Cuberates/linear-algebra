CXX := g++
CXXFLAGS := -std=c++2b -Wall -Wextra -pedantic

TEST_DIR := tests
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/tests
LOG_DIR := $(BUILD_DIR)/logs
LOG_FILE := $(LOG_DIR)/test.log
TEST_BINS := $(patsubst $(TEST_DIR)/%.cpp,$(BIN_DIR)/%,$(TEST_SRCS))

.PHONY: build test clean

build: $(TEST_BINS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(LOG_DIR):
	mkdir -p $(LOG_DIR)

$(BIN_DIR)/%: $(TEST_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

test: build | $(LOG_DIR)
	@: > $(LOG_FILE)
	@passed=0; failed=0; \
	for bin in $(TEST_BINS); do \
		name=$$(basename $$bin); \
		echo "==> Running $$name" | tee -a $(LOG_FILE); \
		if $$bin >> $(LOG_FILE) 2>&1; then \
			echo "[PASS] $$name" | tee -a $(LOG_FILE); \
			passed=$$((passed+1)); \
		else \
			echo "[FAIL] $$name" | tee -a $(LOG_FILE); \
			failed=$$((failed+1)); \
		fi; \
		echo "" >> $(LOG_FILE); \
	done; \
	echo "Summary: $$passed passed, $$failed failed" | tee -a $(LOG_FILE); \
	test $$failed -eq 0

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(TEST_DIR)/tests_runner
