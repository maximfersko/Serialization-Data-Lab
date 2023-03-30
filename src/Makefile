CC = g++ -std=c++17

clean:
	rm -rf  debug.out

build:
	$(CC) *.cc -o src
	./src

debug:
	$(CC) -g *.cc -o debug.out

lint:
	clang-format -i --verbose *.cc *.h