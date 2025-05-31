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

  

- **`make testSerializar`**:

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

  

- **`make testDeserializar`**:

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

make testSerializar

make testDeserializar

rm -f FlightData_serial.bin

```

- **Detalles**: Combina las pruebas para verificar la funcionalidad completa, asegurando que el archivo binario se elimine al final.

  

- **`make valgrindSerializar`**:

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

  

- **`make valgrindDeserializar`**:

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

  

- **`make valgrindTest`**:

- **Descripción**: Ejecuta ambas pruebas de Valgrind (`valgrind_serializar` y `valgrind_deserializar`) y limpia el archivo binario.

- **Comando**:

```bash

make valgrindSerializar

make valgrindDeserializar

rm -f FlightData_serial.bin

```

- **Detalles**: Valida la gestión de memoria en todo el proceso.

  

---

  

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

- **Descripción**: Este test esta diseñado para probar la funcionalidad extra añadida al ejercicio 2 (el comportamiento es el mismo, cambia la lógica de detrás). Se compila

con c++20 para los concepts.

  

- **Comando**:

```bash

g++ -Wall -Wextra -Wpedantic -std=c++20 -I include -o figureTest $^

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

  
---
### Ejercicio 3: Construcción de un JSON

  

El **Ejercicio 3** consiste en implementar un sistema para generar un archivo JSON con una estructura específica que incluye un vector de doubles, un vector de strings y una matriz de enteros. El sistema utiliza dos clases: `DataProcessor`, que maneja la recolección y formato de los datos según su tipo mediante plantillas y `if constexpr`, y `JsonBuilder`, que asocia etiquetas a los datos y construye el JSON final. El programa de prueba (`test.cpp`) ofrece un menú interactivo para agregar datos y visualizar el JSON resultante.

  

#### Estructura del Ejercicio

  

- **include/**: Contiene el archivo de cabecera `JsonBuilder.hpp` con las definiciones de las clases `DataProcessor` y `JsonBuilder`.

- **example/**: Contiene el archivo `test.cpp` con el programa principal que implementa el menú interactivo.

- **Makefile**: Define reglas para compilar y ejecutar el programa, así como para verificar fugas de memoria con Valgrind.

  

#### Opciones del Makefile

  

El `Makefile` proporciona objetivos para compilar, ejecutar y validar el programa. Estos comandos deben ejecutarse desde la carpeta del ejercicio. A continuación, se describen las opciones disponibles:

  

- **`make test`**:

- **Descripción**: Compila y ejecuta el programa principal definido en `example/test.cpp`, utilizando las definiciones en `include/JsonBuilder.hpp`.

- **Comando**:

```bash

g++ -Wall -Wextra -Wpedantic -std=c++17 -I include -o test example/test.cpp

./test

rm test

```

- **Detalles**:

- Genera el ejecutable `test`, lo ejecuta, y lo elimina tras la ejecución.

- Permite interactuar con el menú para construir y visualizar el JSON.

  

- **`make valgrindTest`**:

- **Descripción**: Compila el programa con información de depuración y lo ejecuta con Valgrind para detectar fugas de memoria.

- **Comando**:

```bash

g++ -Wall -Wextra -Wpedantic -std=c++17 -g -I include -o test example/test.cpp

valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./test

rm test

```

- **Detalles**:

- Usa Valgrind con opciones completas para rastrear fugas y errores de memoria.

- Elimina el ejecutable tras la ejecución.

  

#### Uso del Menú en test.cpp

  

El programa `test.cpp` proporciona un menú interactivo para construir el JSON paso a paso. A continuación, se describe cómo usarlo para generar el JSON especificado en el enunciado:

  

1. **Ejecutar el programa**:

- Desde la carpeta del ejercicio, ejecute:

```bash

make test

```

- Esto compila y ejecuta el programa, mostrando el menú.

  

2. **Opciones del menú**:

- **Opción 1: Agregar un valor double**:

- Ingresa valores double (por ejemplo, `1.3`, `2.1`, `3.2`) uno por uno.

- Ejemplo:

```

Seleccione una opcion (1-6): 1

Ingrese un valor double (ejemplo: 1.3): 1.3

Valor 1.3 agregado al vector de doubles.

```

Repita para cada valor (`2.1`, `3.2`).

- **Opción 2: Agregar una palabra (string)**:

- Ingresa palabras (por ejemplo, `Hola`, `Mundo`) una por una.

- Ejemplo:

```

Seleccione una opcion (1-6): 2

Ingrese una palabra: Hola

Palabra "Hola" agregada al vector de strings.

```

Repita para `Mundo`.

- **Opción 3: Agregar una fila de enteros**:

- Ingresa enteros separados por espacios para formar una fila (por ejemplo, `1 2` o `3 4`).

- Ejemplo:

```

Seleccione una opcion (1-6): 3

Ingrese enteros separados por espacios (ejemplo: 1 2): 1 2

Fila agregada a la matriz de enteros.

```

Repita para la segunda fila (`3 4`).

- **Opción 4: Asignar etiqueta y agregar datos al JSON**:

- Ingresa una etiqueta (por ejemplo, `vec_doubles`, `palabras`, `listas`) y selecciona el tipo de datos (1 para doubles, 2 para strings, 3 para matriz de enteros).

- Ejemplo para doubles:

```

Seleccione una opcion (1-6): 4

Ingrese la etiqueta para los datos (ejemplo: vec_doubles): vec_doubles

Seleccione el tipo de datos (1: doubles, 2: strings, 3: matriz de enteros): 1

Datos de doubles con etiqueta "vec_doubles" agregados al JSON.

```

Repita para `palabras` (tipo 2) y `listas` (tipo 3).

- **Opción 5: Imprimir JSON**:

- Muestra el JSON construido.

- Ejemplo de salida esperada:

```

{   "vec_doubles": [1.3, 2.1, 3.2],

	"palabras": ["Hola", "Mundo"],

	"listas": [

	[1,2],

	[3,4]

	]

}

```

- **Opción 6: Salir**:

- Termina el programa.

  

3. **Pasos para generar el JSON del enunciado**:

- Seleccione la opción 1 tres veces para agregar `1.3`, `2.1`, `3.2`.

- Seleccione la opción 2 dos veces para agregar `Hola`, `Mundo`.

- Seleccione la opción 3 dos veces para agregar las filas `1 2` y `3 4`.

- Seleccione la opción 4 tres veces para asignar:

- Etiqueta `vec_doubles` con tipo 1.

- Etiqueta `palabras` con tipo 2.

- Etiqueta `listas` con tipo 3.

- Seleccione la opción 5 para imprimir el JSON.

- Seleccione la opción 6 para salir.

  

4. **Validación de memoria**:

- Ejecute:

```bash

make valgrindTest

```

- Esto verifica que no haya fugas de memoria durante la ejecución del programa.