#pragma once

#include "Conic.hpp"
#include "Point.hpp"

/**
 * @class Circle
 * @brief Representa un círculo, un tipo de sección cónica.
 *
 * Hereda de Conic e implementa la interfaz IFigure para proporcionar
 * funcionalidad para calcular el área y gestionar el radio del círculo.
 */
class Circle : public Conic {
private:
    float radio; ///< Radio del círculo.

public:
    /**
     * @brief Construye un círculo con un punto central y un radio.
     * @param center El punto central del círculo.
     * @param radio El radio del círculo.
     */
    Circle(Point center, float radio);

    /**
     * @brief Obtiene el radio del círculo.
     * @return El radio como float.
     */
    float getRadio() const;

    /**
     * @brief Establece el radio del círculo.
     * @param r El nuevo valor del radio.
     */
    void setRadio(float r);

    /**
     * @brief Calcula el área del círculo (UTILIZADA EN EL EXTRA)
     * @return El área del círculo (π * radio^2) como float.
     */
    float getArea() const;
};