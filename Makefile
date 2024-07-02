CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = src
OBJ_DIR = bin
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(OBJ_DIR) breakout

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

breakout: $(OBJ_FILES)
	$(CXX) $^ -o $@ $(LDFLAGS)

run: breakout
	./breakout

clean:
	rm -rf $(OBJ_DIR) breakout
