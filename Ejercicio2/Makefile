test: example/test.cpp $(wildcard source/*.cpp)
	g++ -Wall -Wextra -Wpedantic -std=c++14 -I include -o figureTest $^
	./figureTest
	rm figureTest

valgrindTest: example/test.cpp $(wildcard source/*.cpp)
	g++ -Wall -Wextra -Wpedantic -std=c++14 -g -I include -o test $^
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./test
	rm test

extraTest: example/test.cpp $(wildcard source/*.cpp)
	g++ -Wall -Wextra -Wpedantic -std=c++20 -I include -o extraTest $^
	./extraTest
	rm extraTest
