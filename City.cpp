//
// Created by paval on 3/8/2019.
//
#include <iostream>
#include "City.hpp"

City::City(int city, int xCord, int yCord) {
    cName = city;
    x = xCord;
    y = yCord;
    cout << cName << endl;
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
