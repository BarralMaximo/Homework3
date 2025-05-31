#pragma once

/**
 * @class IFigure
 * @brief Interfaz para figuras geométricas.
 *
 * Define una interfaz virtual pura para calcular el área de figuras geométricas.
 * Todas las clases derivadas deben implementar el método getArea.
 */
class IFigure {
public:
    /**
     * @brief Calcula el área de la figura (UTILIZADA EN EL EXTRA)
     * @return El área de la figura como un float.
     */
    virtual float getArea() const = 0;
};