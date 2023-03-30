CC = g++ -std=c++17

clean:
	rm -rf  debug.out

build:
	$(CC) *.cpp src/*.cpp  -o s
	./s

debug:
	$(CC) -g *.cc src/*.cpp -o debug.out

lint:
	clang-format -i --verbose *.cc *.h src/*.cc src/*.h 