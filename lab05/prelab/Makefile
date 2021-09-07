# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

Tree: TreeNode.o TreeCalc.o TreeCalcTest.o
	$(CXX) $(DEBUG) TreeNode.o TreeCalc.o TreeCalcTest.o
	@echo "Tree!"

TreeCalc.o: TreeCalc.h TreeCalc.cpp TreeNode.h

TreeNode.o: TreeNode.h TreeNode.cpp

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h

.PHONY: clean
clean:
	-rm -f *.o Tree
