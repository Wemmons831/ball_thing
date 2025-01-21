CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -I./src -I./include -g
SRC_DIR := src
BUILD_DIR := build
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
LIB_DIR := lib
INC_DIR := include
LDFLAGS := -L$(LIB_DIR)
TARGET := release/main.exe
LIB := -lraylib -lopengl32 -lgdi32 -lwinmm



all: $(HEADER_FILES) $(TARGET)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(TARGET): $(OBJS)
	$(CXX) -g -static $(OBJS)  $(LDFLAGS) $(LIB) -o $(TARGET)


clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean