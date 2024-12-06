CXX = g++
CXXFLAGS = -Wall -g -std=c++11
TARGET = my_program.exe
SRC = main.cpp functions.cpp drawmap.cpp
OBJ = $(SRC:.cpp=.o)
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) -lstdc++
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)