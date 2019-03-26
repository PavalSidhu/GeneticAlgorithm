//
// Created by paval on 3/8/2019.
//

#include "Tour.hpp"
#include <cmath>

Tour::Tour(vector<City *> cPoint) {
    tours = cPoint;
    calcFitness();
}

void Tour::calcFitness() {
    double distance = 0;
    for(int i = 0; i < tours.size(); i++) {
        double xDiff = abs(tours[i]->getX() - tours[i + 1]->getX());
        double yDiff = abs(tours[i]->getY() - tours[i + 1]->getY());
        distance += sqrt((pow(xDiff, 2) + pow(yDiff, 2)));
    }
    double xDiff = abs(tours[tours.size() - 1]->getX() - tours[0]->getX());
    double yDiff = abs(tours[tours.size() - 1]->getY() - tours[0]->getY());
    distance += sqrt((pow(xDiff, 2) + pow(yDiff, 2)));
    fitness = distance;
}

double Tour::getFitness() {
    return fitness;
}

vector<City*> Tour::getTour() {
    return tours;
}
