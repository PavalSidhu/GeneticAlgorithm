//
// Created by paval on 3/8/2019.
//
#include <iostream>
#include "City.hpp"

City::City(int city, int xCord, int yCord) {
    cName = city;
    x = xCord;
    y = yCord;
}

City::City(const City &city1) {
    cName = city1.cName;
    x = city1.x;
    y = city1.y;
}

int City::getX() {
    return x;
}

int City::getY() {
    return y;
}

bool operator == (const City &c1, const City &c2) {
    return c1.cName == c2.cName && c1.x == c2.x && c1.y == c2.y;
}