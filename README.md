# Homework3

### Ejercicio 1: Sistema de Datos de Vuelo

El **Ejercicio 1** consiste en implementar un sistema en C++ para gestionar datos de vuelo, incluyendo mediciones de posición (`Posicion`) y presión (`Presion`), que se almacenan en un archivo binario (`FlightData_serial.bin`) mediante serialización. El sistema utiliza una jerarquía de clases con una interfaz (`IMediciones`), una clase base abstracta (`MedicionBase`), y clases derivadas (`Posicion` y `Presion`). La clase `SaveFlightData` coordina la serialización, deserialización, e impresión de los datos, utilizando referencias para evitar copias de objetos, conforme a los requisitos que prohíben el uso de `std::move`.

#### Estructura del Ejercicio

- **include/**: Archivos de cabecera (`Mediciones.hpp`, `Posicion.hpp`, `Presion.hpp`, `SaveFlightSystem.hpp`).
- **source/**: Implementaciones de las clases (`MedicionBase.cpp`, `Posicion.cpp`, `Presion.cpp`, `SaveFlightData.cpp`).
- **main/**: Archivos de prueba (`serializarTest.cpp`, `deserializarTest.cpp`).
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