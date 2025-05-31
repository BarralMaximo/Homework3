#include "Point.hpp"
#include "IFigure.hpp"

/**
 * @class Rectangle
 * @brief Representa un rectángulo, una figura geométrica.
 *
 * Implementa la interfaz IFigure para proporcionar funcionalidad para calcular
 * el área y gestionar el vértice, ancho y alto del rectángulo.
 */
class Rectangle: public IFigure {
private:
    Point vertex; ///< Vértice de referencia del rectángulo.
    float width;  ///< Ancho del rectángulo.
    float height; ///< Alto del rectángulo.

public:
    /**
     * @brief Construye un rectángulo con un vértice, ancho y alto.
     * @param vertex El vértice de referencia del rectángulo.
     * @param w El ancho del rectángulo.
     * @param h El alto del rectángulo.
     */
    Rectangle(Point vertex, float w, float h);

    /**
     * @brief Obtiene el vértice de referencia del rectángulo.
     * @return El vértice como objeto Point.
     */
    Point getVertex() const;

    /**
     * @brief Obtiene el ancho del rectángulo.
     * @return El ancho como float.
     */
    float getWidth() const;

    /**
     * @brief Obtiene el alto del rectángulo.
     * @return El alto como float.
     */
    float getHeight() const;

    /**
     * @brief Establece el vértice de referencia del rectángulo.
     * @param point El nuevo vértice.
     */
    void setVertex(Point point);

    /**
     * @brief Establece el ancho del rectángulo.
     * @param w El nuevo ancho.
     */
    void setWidth(float w);

    /**
     * @brief Establece el alto del rectángulo.
     * @param h El nuevo alto.
     */
    void setHeight(float h);

    /**
     * @brief Calcula el área del rectángulo (UTILIZADA EN EL EXTRA)
     * @return El área del rectángulo (ancho * alto) como float.
     */
    float getArea() const;
};