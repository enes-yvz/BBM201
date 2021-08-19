#include <string>
#include <iostream>
#include <vector>
#include <cmath>
//#include "Operation.h"
#include "Operation.cpp"

using namespace std;

int main(int argc, char **argv) {
    
    Operation operation;
    
    operation.operation(argv[1],argv[2],argv[3],argv[4],argv[5]);
  
    return 0;
}