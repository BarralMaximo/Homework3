#include "Circle.hpp"
#include "Ellipse.hpp"
#include "Rectangle.hpp"

/**
 * @class ProcesadorFigura
 * @brief Clase plantilla para calcular el área de figuras geométricas.
 *
 * Proporciona una implementación genérica que lanza una excepción para tipos
 * no soportados y especializaciones para tipos específicos como Circle, Ellipse
 * y Rectangle.
 */
template<typename T>
class ProcesadorFigura {
public:
    /**
     * @brief Calcula el área de una figura genérica.
     * @param figura La figura cuyo área se desea calcular.
     * @return El área de la figura como float.
     * @throws std::runtime_error Si el tipo de figura no está soportado.
     */
    static float calcularArea(const T& figura) { throw std::runtime_error("Figura no soportada"); }
};

/**
 * @brief Especialización de ProcesadorFigura para Circle.
 */
template<>
class ProcesadorFigura<Circle> {
public:
    /**
     * @brief Calcula el área de un círculo.
     * @param c El círculo cuyo área se desea calcular.
     * @return El área del círculo (π * radio^2) como float.
     */
    static float calcularArea(const Circle& c) { return 3.14159f * c.getRadio() * c.getRadio(); }
};

/**
 * @brief Especialización de ProcesadorFigura para Ellipse.
 */
template<>
class ProcesadorFigura<Ellipse> {
public:
    /**
     * @brief Calcula el área de una elipse.
     * @param e La elipse cuyo área se desea calcular.
     * @return El área de la elipse utilizando su método getArea.
     */
    static float calcularArea(const Ellipse& e) { return e.getArea(); }
};

/**
 * @brief Especialización de ProcesadorFigura para Rectangle.
 */
template<>
class ProcesadorFigura<Rectangle> {
public:
    /**
     * @brief Calcula el área de un rectángulo.
     * @param r El rectángulo cuyo área se desea calcular.
     * @return El área del rectángulo (ancho * alto) como float.
     */
    static float calcularArea(const Rectangle& r) { return r.getWidth() * r.getHeight(); }
};