CC=g++

carver: carver.o
	$(CC) carver.cpp -o build/carver

debug: carver.o
	$(CC) carver.cpp -g -o debug/carver
test: carver.tests.o
	$(CC) carver.tests.cpp -o test/tests
testDebug: carver.tests.o
	$(CC) carver.tests.cpp -g -o test/tests
clean:
	rm -rf *.o debug/* build/* test/tests projectTest/*.pgm_processed.pgm