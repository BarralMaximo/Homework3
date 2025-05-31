#include <iostream>
#include <sstream>
#include "../include/JsonBuilder.hpp"

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

int main() {
    DataProcessor<double> double_processor;
    DataProcessor<std::string> string_processor;
    DataProcessor<int> int_processor;
    JsonBuilder builder;

    while (true) {
        std::cout << "\n=== Menu para construir JSON ===\n";
        std::cout << "1. Agregar un valor double\n";
        std::cout << "2. Agregar una palabra (string)\n";
        std::cout << "3. Agregar una fila de enteros\n";
        std::cout << "4. Asignar etiqueta y agregar datos al JSON\n";
        std::cout << "5. Imprimir JSON\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opcion (1-6): ";

        int option;
        if (!(std::cin >> option)) {
            std::cout << "Entrada invalida. Ingrese un numero entre 1 y 6.\n";
            clearInputBuffer();
            continue;
        }

        switch (option) {
            case 1: {
                std::cout << "Ingrese un valor double (ejemplo: 1.3): ";
                double value;
                if (std::cin >> value) {
                    double_processor.addValue(value);
                    std::cout << "Valor " << value << " agregado al vector de doubles.\n";
                } else {
                    std::cout << "Entrada invalida. Debe ser un numero double.\n";
                    clearInputBuffer();
                }
                break;
            }
            case 2: {
                std::cout << "Ingrese una palabra: ";
                std::string word;
                clearInputBuffer();
                std::getline(std::cin, word);
                if (!word.empty()) {
                    string_processor.addValue(word);
                    std::cout << "Palabra \"" << word << "\" agregada al vector de strings.\n";
                } else {
                    std::cout << "Entrada vacia no permitida.\n";
                }
                break;
            }
            case 3: {
                std::cout << "Ingrese enteros separados por espacios (ejemplo: 1 2). Presione Enter para finalizar: ";
                std::string line;
                clearInputBuffer();
                std::getline(std::cin, line);
                std::vector<int> row;
                std::istringstream iss(line);
                int num;
                while (iss >> num) {
                    row.push_back(num);
                }
                if (!row.empty()) {
                    int_processor.addMatrixRow(row);
                    std::cout << "Fila agregada a la matriz de enteros.\n";
                } else {
                    std::cout << "Entrada invalida. Debe ingresar al menos un entero.\n";
                }
                break;
            }
            case 4: {
                std::cout << "Ingrese la etiqueta para los datos (ejemplo: vec_doubles): ";
                std::string label;
                clearInputBuffer();
                std::getline(std::cin, label);
                if (label.empty()) {
                    std::cout << "La etiqueta no puede estar vacia.\n";
                    break;
                }
                std::cout << "Seleccione el tipo de datos (1: doubles, 2: strings, 3: matriz de enteros): ";
                int type;
                if (!(std::cin >> type) || type < 1 || type > 3) {
                    std::cout << "Tipo invalido. Debe ser 1, 2 o 3.\n";
                    clearInputBuffer();
                    break;
                }
                if (type == 1) {
                    builder.addLabeledData(label, double_processor.toJsonString());
                    std::cout << "Datos de doubles con etiqueta \"" << label << "\" agregados al JSON.\n";
                } else if (type == 2) {
                    builder.addLabeledData(label, string_processor.toJsonString());
                    std::cout << "Datos de strings con etiqueta \"" << label << "\" agregados al JSON.\n";
                } else {
                    builder.addLabeledData(label, int_processor.toJsonString());
                    std::cout << "Matriz de enteros con etiqueta \"" << label << "\" agregada al JSON.\n";
                }
                break;
            }
            case 5: {
                if (!builder.buildJson().empty()) {
                    builder.printJson();
                } else {
                    std::cout << "No se han agregado datos al JSON.\n";
                }
                break;
            }
            case 6: {
                std::cout << "Saliendo del programa.\n";
                return 0;
            }
            default:
                std::cout << "Opcion invalida. Seleccione un numero entre 1 y 6.\n";
                break;
        }
    }

    return 0;
}