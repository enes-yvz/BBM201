#ifndef TRUCK_H
#define TRUCK_H
#include "Package.h"
#include <string>
#include <iostream>

class Truck:public Package
{
public:
    Truck();
    Truck(int truckNum,int packageNum);
    ~Truck();

};

#endif // TRUCK_H