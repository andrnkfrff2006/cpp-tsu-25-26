CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = env_editor

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

clean:
	rm -f $(TARGET) *.env
