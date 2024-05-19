#include <iostream>
#include <iomanip>

#include "cryptolib.h"


using namespace std;


int main() {
    auto ex = getExchange("kucoin");
    if (ex) {
        double price = ex->getPrice("CHZ/USDT");
        cout << setprecision(12) << price << endl;
    } else {
        std::cerr << "Exchange no válido" << std::endl;
    }
    return 0;
}