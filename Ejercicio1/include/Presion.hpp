#pragma once

#include <fstream>
#include "Mediciones.hpp"

/**
 * @class Presion
 * @brief Clase que representa una medición de presión con presión estática, dinámica y tiempo.
 *
 * Hereda de `MedicionBase` para incluir el tiempo de medición y proporciona métodos para
 * serialización, deserialización e impresión de los datos de presión.
 */
class Presion : public MedicionBase {
    public:
        float presionEstatica;  ///< Presión estática (en kPa).
        float presionDinamica; ///< Presión dinámica (en kPa).

        /**
         * @brief Construye un objeto Presion con los valores especificados.
         * @param p Presión estática (por defecto 0.0f).
         * @param q Presión dinámica (por defecto 0.0f).
         * @param t Tiempo de la medición (por defecto 0.0f).
         */
        Presion(float p = 0.0f, float q = 0.0f, float t = 0.0f);

        /**
         * @brief Imprime los datos de la presión en la salida estándar.
         *
         * Muestra el tiempo de medición (obtenido de `MedicionBase`) y los valores de
         * presión estática y dinámica.
         */
        void imprimir() const override;

        /**
         * @brief Serializa los datos de la presión en un archivo binario.
         *
         * Escribe el tiempo de medición (heredado), seguido de presión estática y dinámica,
         * cada uno como 4 bytes en formato binario.
         * @param out Flujo de salida donde se escribirán los datos.
         * @throws std::runtime_error Si ocurre un error al escribir en el archivo.
         */
        void serializar(std::ofstream& out) const override;

        /**
         * @brief Deserializa los datos de la presión desde un archivo binario.
         *
         * Lee el tiempo de medición (heredado), seguido de presión estática y dinámica,
         * en el mismo orden usado por `serializar`.
         * @param in Flujo de entrada desde donde se leerán los datos.
         * @throws std::runtime_error Si ocurre un error al leer el archivo.
         */
        void deserializar(std::ifstream& in) override;

        /**
         * @brief Destructor por defecto.
         */
        ~Presion() = default;
};