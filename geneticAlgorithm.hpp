//
// Created by paval on 3/8/2019.
//

#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include "Tour.hpp"
#include "City.hpp"
#include <vector>

#define PARENT_POOL_SIZE 5

class geneticAlgorithm {
private:
    Tour elite;
public:
    geneticAlgorithm();
    void fittest(vector<Tour> tours);
    void moveFront(vector<Tour> tours);
    void crossover(vector<Tour> tours);
};


#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
