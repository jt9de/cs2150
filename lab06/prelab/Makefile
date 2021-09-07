# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

PZL: timer.o hashTable.o wordPuzzle.o
	$(CXX) $(DEBUG) timer.o hashTable.o wordPuzzle.o
	@echo "PZL!"

timer.o: timer.h timer.cpp

hashTable.o: hashTable.h hashTable.cpp

wordPuzzle.o: wordPuzzle.cpp

.PHONY: clean
clean:
	-rm -f *.o PZL
