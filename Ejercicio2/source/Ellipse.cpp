#include "../include/Ellipse.hpp"

Ellipse::Ellipse(Point center, float a, float b): Conic(center), a(a), b(b){}

float Ellipse::getSMayor() const {return a;}
float Ellipse::getSMenor() const{return b;}

void Ellipse::setSMayor(float mayor) {a = mayor;}
void Ellipse::setSMenor (float menor) {b = menor;}

float Ellipse::getArea() const {return 3.14159f * a * b;}
