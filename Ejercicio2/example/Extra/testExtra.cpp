#include "../include/Extra/FigureTemplate.hpp"

#include <iostream>

int main() {
    Circle c(Point(0.0f, 0.0f), 5.0f);
    Rectangle r(Point(0.0f, 0.0f), 6.0f, 3.0f);

    std::cout << "Área del círculo: " << ProcesadorFigura<Circle>::calcularArea(c) << "\n";
    std::cout << "Área del rectángulo: " << ProcesadorFigura<Rectangle>::calcularArea(r) << "\n";

    return 0;
}