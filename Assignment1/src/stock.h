#ifndef STOCK_H
#define STOCK_H
#include <string>

using namespace std;

class Stock
{
    string stock_list[24];
    string waste[24];
    string display_waste[3];
    string stock_resul;

public:
    Stock(string stock_list[24],string waste[24],string display_waste[3]);
    ~Stock();
    string get_stock_resul();

};

#endif // STOCK_H
