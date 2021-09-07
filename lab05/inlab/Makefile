# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

BST: BinaryNode.o BinarySearchTree.o BSTPathTest.o
	$(CXX) $(DEBUG) BinaryNode.o BinarySearchTree.o BSTPathTest.o
	@echo "BST!"

BinaryNode.o: BinaryNode.h BinaryNode.cpp 

BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp BinaryNode.h

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h

.PHONY: clean
clean:
	-rm -f *.o BST
