CXX = g++
CXXFLAGS = -Wall --std=c++17
GTEST_FLAGS = -lgtest_main -lgtest 

SRC_DIR := src
TEST_DIR := tests
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
HDR_FILES := $(wildcard $(SRC_DIR)/*.hpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_FILES))
TEST_TARGETS := $(patsubst $(TEST_DIR)/%.cpp,$(BIN_DIR)/%,$(TEST_FILES))

all: build test

build: $(OBJ_FILES) $(TEST_OBJ_FILES) $(TEST_TARGETS)

test: $(TEST_TARGETS)
	@for target in $(TEST_TARGETS); do \
		$$target; \
	done

$(BIN_DIR)/%: $(BUILD_DIR)/%.o $(OBJ_FILES) $(TEST_OBJ_FILES)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(GTEST_FLAGS) $< $(OBJ_FILES) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -I $(SRC_DIR) -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -I $(SRC_DIR) -o $@
	
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all build test clean