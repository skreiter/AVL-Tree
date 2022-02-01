# This is an example makefile. A makefile is a file that contains
# a set of directives to automate the build of the software.
# This is a very basic form of a makefile! We will add more to our makefiles in the future!
prog: main.o cancerData.o AVLTree.o AVLNode.o
	g++ main.o cancerData.o AVLTree.o AVLNode.o -o ourProg

main.o: main.cpp AVLTree.hpp cancerData.hpp
	 -g -Wall -std-c++11 main.cpp 

cancerData.o: cancerData.cpp cancerData.hpp
	-g -Wall -std-c++1 message.cpp 

AVLTree.0: AVLTree.hpp AVLNode.hpp
-g -Wall -std-c++1

clean: 
	-rm *.o

run:
	@./ourProg
