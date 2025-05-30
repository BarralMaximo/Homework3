test_serializar: main/serializarTest.cpp $(wildcard source/*.cpp)
	g++ -Wall -Wextra -Wpedantic -std=c++14 -I include -o serializarTest $^
	./serializarTest
	rm serializarTest

test_deserializar: main/deserializarTest.cpp $(wildcard source/*.cpp)
	g++ -Wall -Wextra -Wpedantic -std=c++14 -I include -o deserializarTest $^
	./deserializarTest
	rm deserializarTest

test: test_serializar test_deserializar
	rm -f FlightData_serial.bin


valgrind_serializar: main/serializarTest.cpp $(wildcard source/*.cpp)
	g++ -Wall -Wextra -Wpedantic -std=c++14 -g -I include -o serializarTest $^
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./serializarTest
	rm serializarTest

valgrind_deserializar: main/deserializarTest.cpp $(wildcard source/*.cpp)
	g++ -Wall -Wextra -Wpedantic -std=c++14 -g -I include -o deserializarTest $^
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./deserializarTest
	rm deserializarTest

valgrind_test: valgrind_serializar valgrind_deserializar
	rm -f FlightData_serial.bin

