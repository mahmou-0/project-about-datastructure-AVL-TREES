run: lib.o Build
	./bin/app.exe
	
Build: lib.o
	g++ ./lib/avl.o ./lib/main.o ./lib/read.o ./lib/radix.o -o ./bin/app.exe

lib.o:
	g++ -c ./src/AVL.cpp -o ./lib/avl.o
	g++ -c ./src/read.cpp -o ./lib/read.o
	g++ -c ./src/radix.cpp -o ./lib/radix.o
	g++ -c ./src/main.cpp -o ./lib/main.o

