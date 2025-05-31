#include <iostream>

#include "../include/Procesadorfigura.hpp"

int main() {
    Circle c(Point(0.0f, 0.0f), 5.0f);
    Ellipse e(Point(0.0f, 0.0f), 4.0f, 2.0f);
    Rectangle r(Point(0.0f, 0.0f), 6.0f, 3.0f);

    float areaC = ProcesadorFigura<Circle>::calcularArea(c);
    float areaE = ProcesadorFigura<Ellipse>::calcularArea(e);
    float areaR = ProcesadorFigura<Rectangle>::calcularArea(r);

    std::cout << "Área del círculo: " << areaC << "\n";
    std::cout << "Área de la elipse: " << areaE << "\n";
    std::cout << "Área del rectángulo: " << areaR << "\n";

    return 0;
}