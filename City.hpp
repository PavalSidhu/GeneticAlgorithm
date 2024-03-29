//
// Created by paval on 3/8/2019.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

using namespace std;

class City {
private:
    int x;
    int y;
    int cName;
public:
    City(int city, int xCord, int yCord);
    City(const City& city1);
    int getX();
    int getY();
    int getName();
    friend bool operator == (const City &c1, const City &c2);
};


#endif //GENETICALGORITHM_CITY_HPP
