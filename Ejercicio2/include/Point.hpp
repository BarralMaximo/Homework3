#pragma once

#include <utility>

/**
 * @class Point
 * @brief Representa un punto 2D con coordenadas x e y.
 *
 * Proporciona métodos para obtener y establecer las coordenadas del punto,
 * ya sea individualmente o como un par.
 */
class Point {
private:
    float x; ///< Coordenada x del punto.
    float y; ///< Coordenada y del punto.

public:
    /**
     * @brief Construye un punto con coordenadas específicas.
     * @param x La coordenada x (por defecto 0.0).
     * @param y La coordenada y (por defecto 0.0).
     */
    Point(float x = 0.0f, float y = 0.0f);

    /**
     * @brief Obtiene la coordenada x del punto.
     * @return La coordenada x como float.
     */
    float getCoordx() const;

    /**
     * @brief Obtiene la coordenada y del punto.
     * @return La coordenada y como float.
     */
    float getCoordy() const;

    /**
     * @brief Obtiene las coordenadas del punto como un par.
     * @return Un par de floats con las coordenadas (x, y).
     */
    std::pair<float, float> getPoint() const;

    /**
     * @brief Establece la coordenada x del punto.
     * @param coordx La nueva coordenada x.
     */
    void setX(float coordx);

    /**
     * @brief Establece la coordenada y del punto.
     * @param coordy La nueva coordenada y.
     */
    void setY(float coordy);

    /**
     * @brief Establece ambas coordenadas del punto.
     * @param coordx La nueva coordenada x.
     * @param coordy La nueva coordenada y.
     */
    void setPoint(float coordx, float coordy);
};