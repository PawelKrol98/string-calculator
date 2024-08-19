CXX = clang++
CXXFLAGS = -Wall --std=c++17
GTEST_FLAGS = -lgtest_main -lgtest 

SRC_DIR := string_calculator
TEST_DIR := tests
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin

HDR_FILES := $(wildcard $(SRC_DIR)/*.hpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_FILES))
TEST_TARGET := $(BIN_DIR)/tests

all: build_test run_test

build_test: $(TEST_OBJ_FILES) $(BIN_DIR)/tests

run_test: 
	$(BIN_DIR)/tests

$(BIN_DIR)/tests: $(TEST_OBJ_FILES)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(GTEST_FLAGS) $(TEST_OBJ_FILES) -o $(BIN_DIR)/tests


$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -I $(SRC_DIR) -o $@
	
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all build_test run_test clean