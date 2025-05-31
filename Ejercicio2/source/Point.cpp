#include <utility>

#include "../include/Point.hpp"

Point::Point(float x, float y): x(x), y(y){}

float Point::getCoordx() const {return x;};
float Point::getCoordy() const {return y;};

std::pair<float, float> Point::getPoint() const {return {x, y};}

void Point::setX (float coordx) {x = coordx;}
void Point::setY (float coordy) {y = coordy;}
void Point::setPoint(float coordx, float coordy) {x = coordx; y = coordy;}