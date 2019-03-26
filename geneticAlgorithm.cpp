//
// Created by paval on 3/8/2019.
//

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include "geneticAlgorithm.hpp"

using namespace std;

void geneticAlgorithm::fittest(vector<Tour> tours) {
    Tour minTour = tours[0];
    for(Tour t : tours) {
        if(t.getFitness() < minTour.getFitness()) {
            minTour = t;
        }
    }
    elite = minTour;
};

void geneticAlgorithm::moveFront(vector<Tour> tours) {
    fittest(tours);
    int index = 0;
    for(auto it = tours.begin(); it != tours.end(); ++it) {
        if(it->getFitness() == elite.getFitness()) {
            Tour eliteTour = *it;
            tours.erase(it);
            tours.insert(tours.begin(), eliteTour);
            break;
        }
    }
}

void geneticAlgorithm::crossover(vector<Tour> tours) {
    vector<Tour> subset;
    Tour fitOne;
    Tour fitTwo;
    for(int i = 0; i < PARENT_POOL_SIZE; i++) {
        int t = rand() % tours.size();
        subset.emplace_back(tours[t]);
    }
    fittest(subset);
    moveFront(subset);
    fitOne = subset[0];
    subset.erase(subset.begin());
    fittest(subset);
    moveFront(subset);
    fitTwo = subset[0];
    subset.erase(subset.begin());

    int r = rand() * tours.size();
    vector<City*> crossTour;

    int k = 0;
    for(int i = 0; i < tours.size(); i++) {
        if(i <= r) {
            crossTour[i] = fitOne.getTour()[i];
        } else {
            if(find(crossTour.begin(), crossTour.end(), fitTwo.getTour()[k]) != crossTour.end()) {
                k++;
            } else {
                crossTour[i] = fitTwo.getTour()[i];
                k++;
            }
        }
    }
//    for(k = 0; k <= r; k++) {
//        crossTour[k] = fitOne.getTour()[k];
//    }
//    for(int i = 0; i < tours.size(); i++) {
//        for(int j = 0; j < crossTour.size(); j++) {
//            if(crossTour[j] != fitTwo.getTour()[i]) {
//                k++;
//                crossTour[k] = fitTwo.getTour()[i];
//            }
//        }
//        if(k == tours.size()) {
//            break;
//        }
//    }
}
