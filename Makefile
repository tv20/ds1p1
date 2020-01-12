CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

OBJECTS = programManager.o userData.o

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o main raw.txt encrypted.txt
