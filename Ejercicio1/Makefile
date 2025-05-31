testSerializar: example/serializarTest.cpp $(wildcard source/*.cpp)
	g++ -Wall -Wextra -Wpedantic -std=c++14 -I include -o serializarTest $^
	./serializarTest
	rm serializarTest

testDeserializar: example/deserializarTest.cpp $(wildcard source/*.cpp)
	g++ -Wall -Wextra -Wpedantic -std=c++14 -I include -o deserializarTest $^
	./deserializarTest
	rm deserializarTest

test: testSerializar testDeserializar
	rm -f FlightData_serial.bin


valgrindSerializar: example/serializarTest.cpp $(wildcard source/*.cpp)
	g++ -Wall -Wextra -Wpedantic -std=c++14 -g -I include -o serializarTest $^
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./serializarTest
	rm serializarTest

valgrindDeserializar: example/deserializarTest.cpp $(wildcard source/*.cpp)
	g++ -Wall -Wextra -Wpedantic -std=c++14 -g -I include -o deserializarTest $^
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./deserializarTest
	rm deserializarTest

valgrindTest: valgrindSerializar valgrindDeserializar
	rm -f FlightData_serial.bin