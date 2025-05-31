#pragma once

#include "Point.hpp"
#include "IFigure.hpp"

/**
 * @class Conic
 * @brief Clase base abstracta para secciones cónicas.
 *
 * Hereda de IFigure y proporciona funcionalidad para gestionar el centro
 * de las secciones cónicas. Las clases derivadas deben implementar getArea.
 */
class Conic: public IFigure {
protected:
    Point center; ///< Punto central de la sección cónica.

public:
    /**
     * @brief Construye una sección cónica con un punto central.
     * @param c El punto central de la sección cónica.
     */
    Conic(Point c);

    /**
     * @brief Obtiene el punto central de la sección cónica.
     * @return El punto central como objeto Point.
     */
    Point getCenter() const;

    /**
     * @brief Establece el punto central de la sección cónica.
     * @param c El nuevo punto central.
     */
    void setCenter(Point c);

    /**
     * @brief Calcula el área de la sección cónica (UTILIZADA EN EL EXTRA)
     * @return El área como float (método virtual puro).
     */
    virtual float getArea() const = 0;
};