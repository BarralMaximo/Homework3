#pragma once

/// @file Procesadorfigura.hpp
/// @brief Plantilla genérica para el cálculo de áreas de figuras geométricas.
/// 
/// Este archivo define un concepto `hasArea` y una clase plantilla `ProcesadorFigura`.
/// El concepto `hasArea` asegura que el tipo pasado como parámetro tenga un método `getArea()`
/// que devuelva un `float` (o un tipo convertible a `float`).
///
/// La clase `ProcesadorFigura` está especializada para tipos que cumplen con este concepto
/// y permite calcular el área de la figura mediante una función estática `calcularArea`.
/// 
/// Como se menciono en el README.md, esta solución es extra a los requerimientos de la consigna. Sin embargo, considero que es más útil ya que permite realizar una 
/// plantilla más general que aumenta su escalabilidad, permitiendo incluir más figuras de forma sencilla en un futuro.

#include <concepts>

#include "../Circle.hpp"
#include "../Ellipse.hpp"
#include "../Rectangle.hpp"

/// @concept hasArea
/// @brief Concepto que valida que un tipo T tenga un método getArea() que devuelva un float.
template<typename T>
concept hasArea = requires(T t) {
    { t.getArea() } -> std::convertible_to<float>;
};

/// @class ProcesadorFigura
/// @brief Clase plantilla para calcular el área de figuras que cumplen con el concepto hasArea.
/// 
/// Esta clase proporciona un método estático `calcularArea` que llama a `getArea()`
/// sobre una figura del tipo T.
template<hasArea T>
class ProcesadorFigura {
public:
    /// @brief Calcula el área de la figura pasada como parámetro.
    /// @param figura Figura geométrica que cumple con el concepto hasArea.
    /// @return Área de la figura como float.
    static float calcularArea(const T& figura) {
        return figura.getArea();
    }
};
