# Homework3

### Ejercicio 1: Sistema de Datos de Vuelo

El **Ejercicio 1** consiste en implementar un sistema para gestionar datos de vuelo, incluyendo mediciones de posición (`Posicion`) y presión (`Presion`), que se almacenan en un archivo binario (`FlightData_serial.bin`) mediante serialización. El sistema utiliza una jerarquía de clases con una interfaz (`IMediciones`), una clase base abstracta (`MedicionBase`), y clases derivadas (`Posicion` y `Presion`). La clase `SaveFlightData` coordina la serialización, deserialización, e impresión de los datos, utilizando referencias para evitar copias de objetos, conforme a los requisitos que prohíben el uso de `std::move`.

#### Estructura del Ejercicio

- **include/**: Archivos de cabecera (`Mediciones.hpp`, `Posicion.hpp`, `Presion.hpp`, `SaveFlightSystem.hpp`).
- **source/**: Implementaciones de las clases (`MedicionBase.cpp`, `Posicion.cpp`, `Presion.cpp`, `SaveFlightData.cpp`).
- **example/**: Archivos de prueba (`serializarTest.cpp`, `deserializarTest.cpp`).
- **FlightData_serial.bin**: Archivo binario generado durante las pruebas.

#### Opciones del Makefile

El `Makefile` proporciona objetivos para compilar, ejecutar pruebas, y validar la memoria del programa. Estas opciones deben ejecutarse desde la carpeta Ejercicio1. A continuación, se describen las opciones disponibles:

- **`make test_serializar`**:
  - **Descripción**: Compila y ejecuta las pruebas de serialización definidas en `main/serializarTest.cpp`, junto con todas las implementaciones en `source/*.cpp`.
  - **Comando**:
    ```bash
    g++ -Wall -Wextra -Wpedantic -std=c++14 -I include -o serializarTest main/serializarTest.cpp source/*.cpp
    ./serializarTest
    rm serializarTest
    ```
  - **Detalles**:
    - Genera el ejecutable `serializarTest`, lo ejecuta, y lo elimina tras la ejecución.
    - Crea `FlightData_serial.bin` con los datos serializados.

- **`make test_deserializar`**:
  - **Descripción**: Compila y ejecuta las pruebas de deserialización definidas en `main/deserializarTest.cpp`, junto con todas las implementaciones en `source/*.cpp`.
  - **Comando**:
    ```bash
    g++ -Wall -Wextra -Wpedantic -std=c++14 -I include -o deserializarTest main/deserializarTest.cpp source/*.cpp
    ./deserializarTest
    rm deserializarTest
    ```
  - **Detalles**:
    - Verifica la lectura correcta de `FlightData_serial.bin`.
    - Genera el ejecutable `deserializarTest`, lo ejecuta, y lo elimina tras la ejecución.

- **`make test`**:
  - **Descripción**: Ejecuta ambas pruebas (`test_serializar` y `test_deserializar`) y limpia el archivo binario generado.
  - **Comando**:
    ```bash
    make test_serializar
    make test_deserializar
    rm -f FlightData_serial.bin
    ```
  - **Detalles**: Combina las pruebas para verificar la funcionalidad completa, asegurando que el archivo binario se elimine al final.

- **`make valgrind_serializar`**:
  - **Descripción**: Compila las pruebas de serialización con información de depuración y las ejecuta con Valgrind para detectar fugas de memoria.
  - **Comando**:
    ```bash
    g++ -Wall -Wextra -Wpedantic -std=c++14 -g -I include -o serializarTest main/serializarTest.cpp source/*.cpp
    valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./serializarTest
    rm serializarTest
    ```
  - **Detalles**:
    - Usa Valgrind con opciones completas para rastrear fugas y errores.
    - Elimina el ejecutable tras la ejecución.

- **`make valgrind_deserializar`**:
  - **Descripción**: Compila las pruebas de deserialización con información de depuración y las ejecuta con Valgrind.
  - **Comando**:
    ```bash
    g++ -Wall -Wextra -Wpedantic -std=c++14 -g -I include -o deserializarTest main/deserializarTest.cpp source/*.cpp
    valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./deserializarTest
    rm deserializarTest
    ```
  - **Detalles**:
    - Usa Valgrind con opciones completas para rastrear fugas y errores.
    - Elimina el ejecutable tras la ejecución.

- **`make valgrind_test`**:
  - **Descripción**: Ejecuta ambas pruebas de Valgrind (`valgrind_serializar` y `valgrind_deserializar`) y limpia el archivo binario.
  - **Comando**:
    ```bash
    make valgrind_serializar
    make valgrind_deserializar
    rm -f FlightData_serial.bin
    ```
  - **Detalles**: Valida la gestión de memoria en todo el proceso.

### Ejercicio 2: Figuras Geométricas y Programación Genérica

El **Ejercicio 2** consiste en implementar un sistema que represente distintas figuras geométricas: `Circle`, `Ellipse`, `Rectangle`, todas ellas construidas a partir de un punto base (`Point`). Cada clase cuenta con sus atributos y métodos `set/get`, así como un constructor apropiado. Además, se implementa una clase `ProcesadorFigura` que usa **especialización de plantillas** para calcular el área de cada figura.

El sistema permite probar el cálculo de áreas para cada figura mediante un programa principal.

>**IMPORTANTE:** Con el afán de diseñar una solución más generica y mejorar mi habilidad con los templates, desarrollé una implementación sin utilizar especialización de plantilla. Sin embargo, esto no es lo que pedía la consigna, por lo que la dejé como un extra. Es importante mencionar que la función getArea() esta creada para ser utilizada en esta solución, por lo tanto, no fue tenida en cuenta para el diseño de Procesadorfigura.hpp. Respetando así la consigna: "Cree una clase adicional denominada ProcesadorFigura que utilice especialización de plantilla para calcular el área de las figuras". La deje en el homework final ya que considero que sería una mejor forma de implementarlo, mejorando la escalabilidad y generalidad.

#### Estructura del Ejercicio

- **include/**: Archivos de cabecera:
  - `Point.hpp`
  - `Circle.hpp`
  - `Ellipse.hpp`
  - `Rectangle.hpp`
  - `IFigure.hpp`
  - `Conic.hpp`
  - `Procesadorfigura.hpp`

- **example/**: Contiene el archivo de prueba:
  - `test.cpp`: Crea instancias de las figuras y utiliza `ProcesadorFigura` para calcular sus áreas.

#### Opciones del Makefile

El `Makefile` proporciona objetivos para compilar, ejecutar el programa principal y verificar memoria con Valgrind. Estas opciones deben ejecutarse desde la carpeta `Ejercicio2`.

- **`make test`**:
  - **Descripción**: Compila el test principal junto con todos los headers e implementaciones.
  - **Comando**:
    ```bash
    	g++ -Wall -Wextra -Wpedantic -std=c++14 -I include -o figureTest $^
	    ./figureTest
	    rm figureTest
    ```

    - **`make extraTest`**:
  - **Descripción**: Este test esta diseñado para probar la funcionalidad extra añadida al ejercicio 2 (el comportamiento es el mismo, cambia la lógica de detrás)

  - **Comando**:
    ```bash
    	g++ -Wall -Wextra -Wpedantic -std=c++14 -I include -o figureTest $^
	    ./figureTest
	    rm figureTest
    ```

- **`make valgrindTest`**:
  - **Descripción**: Compila con símbolos de depuración y ejecuta con Valgrind para detectar fugas de memoria.
  - **Comando**:
    ```bash
    g++ -Wall -Wextra -Wpedantic -std=c++14 -g -I include -o test $^
	  valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./test
	  rm test
    ```

  - **Detalles**:
    - Usa Valgrind con opciones completas para rastrear fugas y errores.
    - Elimina el ejecutable tras la ejecución.