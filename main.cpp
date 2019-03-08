#include <iostream>

#include "City.hpp"
#include "Tour.hpp"

#include <iostream>
#include <algorithm>

#define CITIES_IN_TOUR 32
#define POPULATION_SIZE 32
#define SHUFFLES 64
#define ITERATIONS 1000
#define MAP_BOUNDARY 1000
#define PARENT_POOL_SIZE 5
#define MUTATION_RATE 15
#define NUMBER_OF_ELITES 1

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
        vector<City*> cPoint;
        for( int b = 0; b < CITIES_IN_TOUR; b++) {
            cPoint.emplace_back(new City(masterList[b]));
        }
        tourList.emplace_back(cPoint);
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}