#include "Package.h"
#include <string>
#include <iostream>

using namespace std;

int packageNum;
int truckNum;

Package::Package()
{
    
}

Package::Package(int truckNum,int packageNum)
{
    this->packageNum= packageNum;
    
    this->truckNum = truckNum;
}

Package::~Package()
{
}

