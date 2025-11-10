geometry.exe: main.cpp
	g++ -g -std=c++17 main.cpp -o geometry.exe

.PHONY: all run clean
all: geometry.exe
run: geometry.exe
	./geometry.exe
clean:
	rm -f *.o geometry.exe
