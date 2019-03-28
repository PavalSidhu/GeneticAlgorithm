//
// Created by paval on 3/8/2019.
//

#include "Tour.hpp"
#include <cmath>
#include <random>
#include <algorithm>
#include <iostream>

Tour::Tour(vector<City> cPoint) {
    for(int i = 0; i < cPoint.size(); ++i) {
        City* city = new City(cPoint[i]);
        this-> tours.emplace_back(city);
    }
    this->fitness = calcFitness();
}

Tour::Tour() {}

Tour::Tour(const Tour &t) {
    tours = t.tours;
    fitness = t.fitness;
}
double Tour::calcFitness() {
    double distance = 0;
    for(int i = 0; i < tours.size() - 1; i++) {
        double xDiff = abs(tours[i]->getX() - tours[i + 1]->getX());
        double yDiff = abs(tours[i]->getY() - tours[i + 1]->getY());
        distance += sqrt((pow(xDiff, 2) + pow(yDiff, 2)));
    }
    double xDiff = abs(tours[tours.size() - 1]->getX() - tours[0]->getX());
    double yDiff = abs(tours[tours.size() - 1]->getY() - tours[0]->getY());
    distance += sqrt((pow(xDiff, 2) + pow(yDiff, 2)));
    return distance;
}

double Tour::getFitness() {
    return fitness;
}

vector<City*> Tour::getTour() {
    return tours;
}
