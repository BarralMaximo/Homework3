#pragma once

#include <fstream>
#include <memory>

/**
 * @class IMediciones
 * @brief Interfaz pura para clases que representan mediciones de vuelo serializables.
 *
 * Define los métodos virtuales puros para serialización, deserialización e impresión,
 * asegurando que las clases derivadas implementen estas funcionalidades.
 */
class IMediciones {
    public:
        /**
         * @brief Serializa los datos de la medición en un archivo binario.
         * @param out Flujo de salida donde se escribirán los datos.
         */
        virtual void serializar(std::ofstream& out) const = 0;

        /**
         * @brief Deserializa los datos de la medición desde un archivo binario.
         * @param in Flujo de entrada desde donde se leerán los datos.
         */
        virtual void deserializar(std::ifstream& in) = 0;

        /**
         * @brief Destructor virtual para garantizar una destrucción adecuada en la jerarquía.
         */
        virtual ~IMediciones() = default;
};

/**
 * @class MedicionBase
 * @brief Clase base abstracta para mediciones de vuelo con un tiempo asociado.
 *
 * Gestiona un tiempo de medición almacenado en un `std::unique_ptr<float>` y proporciona
 * una implementación base para serialización y deserialización. Las clases derivadas
 * deben implementar el método `imprimir`.
 */
class MedicionBase : public IMediciones {
    protected:
        std::unique_ptr<float> tiempoMedicion; ///< Tiempo de la medición, gestionado dinámicamente.

    public:
        /**
         * @brief Construye una medición con un tiempo especificado.
         * @param tiempoMedicion Valor del tiempo de la medición.
         */
        MedicionBase(float tiempoMedicion);

        /**
         * @brief Obtiene el tiempo de la medición.
         * @return El valor del tiempo de la medición.
         */
        float getTiempo() const;

        /**
         * @brief Imprime los datos de la medición en la salida estándar.
         *
         * Método puro que debe ser implementado por las clases derivadas.
         */
        virtual void imprimir() const = 0;

        /**
         * @brief Serializa el tiempo de la medición en un archivo binario.
         *
         * Escribe los 4 bytes del valor `tiempoMedicion` en el flujo de salida.
         * @param out Flujo de salida donde se escribirán los datos.
         * @throws std::runtime_error Si ocurre un error al escribir.
         */
        virtual void serializar(std::ofstream& out) const override;

        /**
         * @brief Deserializa el tiempo de la medición desde un archivo binario.
         *
         * Lee 4 bytes desde el flujo de entrada y actualiza `tiempoMedicion`.
         * @param in Flujo de entrada desde donde se leerán los datos.
         * @throws std::runtime_error Si ocurre un error al leer el archivo.
         */
        virtual void deserializar(std::ifstream& in) override;

        /**
         * @brief Destructor virtual para garantizar una destrucción adecuada.
         */
        virtual ~MedicionBase() = default;
};