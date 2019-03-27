//
// Created by paval on 3/8/2019.
//

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include "geneticAlgorithm.hpp"

using namespace std;

geneticAlgorithm::geneticAlgorithm() {}

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
    for(int i = 0; i < tours.size(); i++) {
        Tour fitOne;
        Tour fitTwo;
        for(int i = 0; i < PARENT_POOL_SIZE; i++) {
            int t = rand() % tours.size();
            subset.emplace_back(tours[t]);
        }
        moveFront(subset);
        fitOne = subset[0];
        vector<Tour> newsubset;
        for (int j = 1; j < subset.size(); ++j) {
            newsubset.emplace_back(subset[j]);
        }
        fittest(newsubset);
        moveFront(newsubset);
        fitTwo = newsubset[0];

        int r = rand() % tours.size();
        vector<City> crossTour;
        int k = 0;
        for(int i = 0; i < tours.size(); i++) {
            if(i <= r) {
                crossTour.emplace_back(*fitOne.getTour()[i]) ;
            } else {
                if(find(crossTour.begin(), crossTour.end(), (*fitTwo.getTour()[k])) != crossTour.end()) {
                    k++;
                } else {
                    crossTour.emplace_back(*fitTwo.getTour()[k]);
                    k++;
                }
            }
            Tour temp(crossTour);
            tours[i] = temp;
        }
    }
}

void geneticAlgorithm::mutation(vector<Tour> tours) {
    fittest(tours);
    moveFront(tours);
    for(int i = 1; i < tours.size(); i++) {
        for(int j = 0; j < tours.size(); j++) {
            int r = rand() % 101;
            if(r < MUTATION_RATE) {
                int j = rand() % 1;
                if(i == tours.size()-1) {
                    swap(tours[i].getTour()[j], tours[i].getTour()[j - 1]);
                } else if(i == 0) {
                    swap(tours[i].getTour()[j], tours[i].getTour()[j + 1]);
                }else{
                    if(j == 0) {
                        swap(tours[i].getTour()[j], tours[i].getTour()[j + 1]);
                    } else {
                        swap(tours[i].getTour()[j], tours[i].getTour()[j - 1]);
                    }
                }

            }
        }
    }
}

void geneticAlgorithm::evaluation(vector<Tour> tours) {
    cout << "bye" << endl;
    for(int i = 0; i < tours.size(); i++) {
        tours[i].calcFitness();
        cout << tours[i].getFitness() << endl;
    }
}
