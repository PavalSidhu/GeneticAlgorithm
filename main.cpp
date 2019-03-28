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
    double bestDistance = 1000000000;
    double base;
    Tour baseRoute;
    Tour bestRoute;

    srand(time(nullptr));
    for(int i = 0; i < CITIES_IN_TOUR; i++) {
        int x = rand() % 1001;
        int y = rand() % 1001;
        masterList.emplace_back(City(i, x, y));
    }


    for(int i = 0; i < ITERATIONS; ++i) {
        vector<Tour> tourList;
        for(int i = 0; i < POPULATION_SIZE; i++) {
            random_shuffle(masterList.begin(), masterList.end());
            Tour temp(masterList);
            tourList.emplace_back(temp);
        }
        cout << "Iteration number : " << i << endl;
        geneticAlgorithm g;
        g.fittest(tourList);
        g.crossover(tourList);
        g.mutation(tourList);
        g.evaluation(tourList);
        g.totalDistance(tourList);
        if(i == 0) {
            base = g.getBestDistance();
            baseRoute = g.getFittest();
        }
        cout << "The elite tour in this iteration has a distance of : " << g.getBestDistance() << endl;
        if(g.getBestDistance() < bestDistance) {
            cout << "This iteration has improved by : " << bestDistance - g.getBestDistance() << endl;
            bestDistance = g.getBestDistance();
            bestRoute = g.getFittest();
        } else {
            cout << "This iteration has not improved" << endl;
        }
        cout << "The best distance so far is : " << bestDistance << endl;
        cout << "The improvement from the base is : " << base - bestDistance << endl;
    }

    cout << "Number of iterations : " << ITERATIONS << endl;
    cout << "The base distance is : " << base << endl;
    cout << "The best distance is : " << bestDistance << endl;
    if(base > bestDistance) {
        cout << "Improvement factor was achieved" << endl;
    } else {
        cout << "Improvement factor was not achieved" << endl;
    }
    cout << "The output of the base route is : " << endl;
    for(int i = 0; i < baseRoute.getTour().size(); i++) {
        cout << baseRoute.getTour()[i]->getName() << endl;
    }
    cout << baseRoute.getTour()[0]->getName() << endl;
    cout << "The output of the best route is : " << endl;
    for(int i = 0; i < bestRoute.getTour().size(); i++) {
        cout << bestRoute.getTour()[i]->getName() << endl;
    }
    cout << bestRoute.getTour()[0]->getName() << endl;
    return 0;
}