#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
#include <iostream>

class Package
{
    
public:

    int packageNum;
    int truckNum;

    Package();
    Package(int truckNum,int packageNum);
    ~Package();

};

#endif // PACKAGE_H

