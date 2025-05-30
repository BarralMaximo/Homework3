#pragma once

#include <fstream>
#include "Mediciones.hpp"

/**
 * @class Posicion
 * @brief Clase que representa una medición de posición geográfica con latitud, longitud, altitud y tiempo.
 *
 * Hereda de `MedicionBase` para incluir el tiempo de medición y proporciona métodos para
 * serialización, deserialización e impresión de los datos de posición.
 */
class Posicion : public MedicionBase {
    public:
        float latitud;  ///< Latitud de la posición (en grados).
        float longitud; ///< Longitud de la posición (en grados).
        float altitud;  ///< Altitud de la posición (en metros).

        /**
         * @brief Construye un objeto Posicion con los valores especificados.
         * @param latitud Latitud de la posición (por defecto 0.0f).
         * @param longitud Longitud de la posición (por defecto 0.0f).
         * @param altitud Altitud de la posición (por defecto 0.0f).
         * @param t Tiempo de la medición (por defecto 0.0f).
         */
        Posicion(float latitud = 0.0f, float longitud = 0.0f, float altitud = 0.0f, float t = 0.0f);

        /**
         * @brief Imprime los datos de la posición en la salida estándar.
         *
         * Muestra el tiempo de medición (obtenido de `MedicionBase`) y los valores de
         * latitud, longitud, y altitud.
         */
        void imprimir() const override;

        /**
         * @brief Serializa los datos de la posición en un archivo binario.
         *
         * Escribe el tiempo de medición (heredado), seguido de latitud, longitud, y altitud,
         * cada uno como 4 bytes en formato binario.
         * @param out Flujo de salida donde se escribirán los datos.
         * @throws std::runtime_error Si ocurre un error al escribir en el archivo.
         */
        void serializar(std::ofstream& out) const override;

        /**
         * @brief Deserializa los datos de la posición desde un archivo binario.
         *
         * Lee el tiempo de medición (heredado), seguido de latitud, longitud, y altitud,
         * en el mismo orden usado por `serializar`.
         * @param in Flujo de entrada desde donde se leerán los datos.
         * @throws std::runtime_error Si ocurre un error al leer el archivo.
         */
        void deserializar(std::ifstream& in) override;

        /**
         * @brief Destructor por defecto.
         */
        ~Posicion() = default;
};