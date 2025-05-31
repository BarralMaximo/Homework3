/*3. Escriba un código que permita crear el siguiente JSON:
{ 
"vec_doubles" : [1.3, 2.1, 3.2], // Aquí sólo se utiliza el tipo de dato double
"palabras" : ["Hola", "Mundo"], // Aquí sólo se utiliza el tipo de dato std::string
"listas" : [ // Las listas sólo deben ser creadas con tipos de datos enteros
[1, 2],
[3, 4]
]
}

Para lograr esto, cree dos clases que colaboren para construir el JSON en partes
separadas:

1. Clase 1: esta clase se encargará de generar los vectores de double y std::string,
así como la matriz de enteros. Para ello, se debe utilizar un método para agregar
los valores y las palabras a la instancia de la clase para luego procesarlas según
el tipo de dato que se pasó.
Deberá utilizar un template para poder trabajar con los distintos tipos de datos.
En función del tipo, y mediante el uso obligatorio de “if constexpr”, se deberán
aplicar distintos métodos para procesar los datos adecuadamente.

2. Clase 2: Esta clase se encargará de asociar etiquetas (por ejemplo, “palabras”)
con su vector/matriz correspondiente (por ejemplo, [“Hola”, “Mundo”]).
Además, contendrá el método que finalmente construya el JSON completo y lo
imprima por pantalla.
Cree un programa que utilice estas clases para crear y visualizar el JSON resultante. El
formato de salida debe coincidir con el mostrado al inicio del enunciado.*/



