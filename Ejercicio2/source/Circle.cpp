#include "../include/Circle.hpp"

Circle::Circle(Point center, float radio): Conic(center), radio(radio){}

float Circle::getRadio() const {return radio;}

void Circle::setRadio(float r) {radio = r;}

float Circle::getArea() const {return 3.14159f * radio * radio;}