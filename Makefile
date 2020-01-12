CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

OBJECTS = programManager.o userData.o hashing.o node.o linkedList.o

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o main raw.txt encrypted.txt
