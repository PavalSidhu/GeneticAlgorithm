//
// Created by paval on 3/8/2019.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include "City.hpp"

using namespace std;

class Tour {
private:
    vector<City*> tours;
    double fitness;
public:
    Tour();
    Tour(vector<City*> cPoint);
    void calcFitness();
    double getFitness();
    vector<City*> getTour();
};


#endif //GENETICALGORITHM_TOUR_HPP
