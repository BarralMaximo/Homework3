#include "../include/Rectangle.hpp"

Rectangle::Rectangle(Point vertex, float w, float h): vertex(vertex), width(w), height(h){}

Point Rectangle::getVertex() const {return vertex;}
float Rectangle::getWidth() const {return width;}
float Rectangle::getHeight() const {return height;}

void Rectangle::setVertex(Point point) {vertex = point;}
void Rectangle::setWidth(float w) {width = w;}
void Rectangle::setHeight (float h) {height = h;}

float Rectangle::getArea() const {return width * height;}