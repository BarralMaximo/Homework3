#pragma once

#include <fstream>
#include <memory>

#include "Presion.hpp"
#include "Posicion.hpp"

/**
 * @class SaveFlightData
 * @brief Clase que gestiona la serialización, deserialización e impresión de datos de vuelo (posición y presión).
 *
 * Almacena referencias a objetos `Posicion` y `Presion`, permitiendo guardar y recuperar sus datos en un archivo binario
 * sin realizar copias de los objetos, conforme a los requisitos de la consigna que prohíben el uso de `std::move`.
 */
class SaveFlightData {
    public:
        Posicion& posicion; ///< Referencia al objeto Posicion que contiene datos de latitud, longitud, altitud y tiempo.
        Presion& presion;   ///< Referencia al objeto Presion que contiene datos de presión estática, dinámica y tiempo.

        /**
         * @brief Construye un objeto SaveFlightData con referencias a objetos Posicion y Presion.
         * @param pos Referencia al objeto Posicion.
         * @param pres Referencia al objeto Presion.
         */
        SaveFlightData(Posicion& pos, Presion& pres);

        /**
         * @brief Serializa los datos de posición y presión en un archivo binario.
         *
         * Escribe los datos de `posicion` y `presion` en el flujo de salida en formato binario, siguiendo
         * el orden definido por sus métodos `serializar`.
         * @param out Flujo de salida donde se escribirán los datos.
         * @throws std::runtime_error Si ocurre un error al escribir en el archivo.
         */
        void serializar(std::ofstream& out) const;

        /**
         * @brief Deserializa los datos de posición y presión desde un archivo binario.
         *
         * Lee los datos desde el flujo de entrada y actualiza los objetos `posicion` y `presion`,
         * siguiendo el orden definido por sus métodos `deserializar`.
         * @param in Flujo de entrada desde donde se leerán los datos.
         * @throws std::runtime_error Si ocurre un error al leer el archivo.
         */
        void deserializar(std::ifstream& in);

        /**
         * @brief Imprime los datos de posición y presión en la salida estándar.
         *
         * Llama a los métodos `imprimir` de `posicion` y `presion` para mostrar sus datos.
         */
        void imprimir();
};