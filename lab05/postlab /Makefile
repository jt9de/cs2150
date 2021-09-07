# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

AVL: AVLNode.o AVLTree.o AVLPathTest.o
	$(CXX) $(DEBUG) AVLNode.o AVLTree.o AVLPathTest.o
	@echo "AVL!"

AVLNode.o: AVLNode.h AVLNode.cpp 

AVLTree.o: AVLTree.h AVLTree.cpp AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h

.PHONY: clean
clean:
	-rm -f *.o AVL
