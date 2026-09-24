CXX = clang++
CXXFLAGS = -Wall --std=c++17
GTEST_FLAGS = -lgtest_main -lgtest 

SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

SRC_OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/test_%.o,$(TEST_FILES))

TEST_TARGET := $(BIN_DIR)/tests

.PHONY: all build_test run_test clean

all: run_test

build_test: $(TEST_TARGET)

run_test: $(TEST_TARGET)
	$(TEST_TARGET)

$(TEST_TARGET): $(SRC_OBJ_FILES) $(TEST_OBJ_FILES)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ $(GTEST_FLAGS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
