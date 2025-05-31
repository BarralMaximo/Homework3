test: example/test.cpp
	g++ -Wall -Wextra -Wpedantic -std=c++17 -I include -o test $^
	./test
	rm test

valgrindTest: example/test.cpp
	g++ -Wall -Wextra -Wpedantic -std=c++17 -g -I include -o test $^
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./test
	rm test
