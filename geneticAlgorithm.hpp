//
// Created by paval on 3/8/2019.
//

#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include "Tour.hpp"
#include "City.hpp"
#include <vector>

#define PARENT_POOL_SIZE 5
#define MUTATION_RATE 15

class geneticAlgorithm {
private:
    Tour elite;
    double minDistance;
public:
    geneticAlgorithm();
    void fittest(vector<Tour> tours);
    void moveFront(vector<Tour> tours);
    void crossover(vector<Tour> tours);
    void mutation(vector<Tour> tours);
    void evaluation(vector<Tour> tours);
};


#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
