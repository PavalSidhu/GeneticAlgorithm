#include <iostream>
#include <algorithm>

#include "City.hpp"
#include "Tour.hpp"
#include "geneticAlgorithm.hpp"



#define CITIES_IN_TOUR 32
#define POPULATION_SIZE 32
#define ITERATIONS 1000
#define PARENT_POOL_SIZE 5
#define MUTATION_RATE 15

int main() {
    vector<City> masterList;
    vector<Tour> tourList;


    srand(time(nullptr));
    for(int i = 0; i < CITIES_IN_TOUR; i++) {
        int x = rand() % 1001;
        int y = rand() % 1001;
        masterList.emplace_back(City(i, x, y));
    }

    for(int i = 0; i < POPULATION_SIZE; i++) {
        random_shuffle(masterList.begin(), masterList.end());
        Tour temp(masterList);
        tourList.emplace_back(temp);
    }

    for(int i = 0; i < ITERATIONS; ++i) {
        cout << "Iteration number : " << i << endl;
        geneticAlgorithm g;
        g.fittest(tourList);
        g.crossover(tourList);
        g.mutation(tourList);
        g.evaluation(tourList);
        g.totalDistance(tourList);
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}