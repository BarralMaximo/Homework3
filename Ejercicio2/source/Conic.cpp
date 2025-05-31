#include "../include/Conic.hpp"

Conic::Conic(Point center): center(center){}

Point Conic::getCenter() const {return center;}
void Conic::setCenter(Point point) {center = point;}