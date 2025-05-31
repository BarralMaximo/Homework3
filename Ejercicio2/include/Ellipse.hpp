#pragma once

#include "Conic.hpp"
#include "Point.hpp"

/**
 * @class Ellipse
 * @brief Representa una elipse, un tipo de sección cónica.
 *
 * Hereda de Conic e implementa la interfaz IFigure para proporcionar
 * funcionalidad para calcular el área y gestionar los ejes semi-mayor y
 * semi-menor de la elipse.
 */
class Ellipse : public Conic {
private:
    float a; ///< Longitud del eje semi-mayor.
    float b; ///< Longitud del eje semi-menor.

public:
    /**
     * @brief Construye una elipse con un punto central y longitudes de ejes.
     * @param center El punto central de la elipse.
     * @param a La longitud del eje semi-mayor.
     * @param b La longitud del eje semi-menor.
     */
    Ellipse(Point center, float a, float b);

    /**
     * @brief Obtiene la longitud del eje semi-mayor.
     * @return La longitud del eje semi-mayor como float.
     */
    float getSMayor() const;

    /**
     * @brief Obtiene la longitud del eje semi-menor.
     * @return La longitud del eje semi-menor como float.
     */
    float getSMenor() const;

    /**
     * @brief Establece la longitud del eje semi-mayor.
     * @param mayor La nueva longitud del eje semi-mayor.
     */
    void setSMayor(float mayor);

    /**
     * @brief Establece la longitud del eje semi-menor.
     * @param menor La nueva longitud del eje semi-menor.
     */
    void setSMenor(float menor);

    /**
     * @brief Calcula el área de la elipse (UTILIZADA EN EL EXTRA)
     * @return El área de la elipse (π * a * b) como float.
     */
    float getArea() const;
};