CXX := g++
CXXFLAGS := -Wall -std=c++17 `sdl2-config --cflags`
LDFLAGS := `sdl2-config --libs` -lSDL2_ttf
SRC_DIR := d:/tetris-sdl/src
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:.cpp=.o)
TARGET := tetris-sdl.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

.PHONY: all clean