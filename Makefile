CC=g++

carver: carver.o
	$(CC) carver.cpp -o carver

debug: carver.o
	$(CC) carver.cpp -o -g carver
test: carver.tests.o
	$(CC) carver.tests.cpp -o tests
