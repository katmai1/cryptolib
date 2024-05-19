// #include <iostream>
#include <iomanip>

#include "cryptolib.h"


using namespace std;


int main() {
    auto ex = getExchange("bingx");
    if (ex) {
        double lastPrice = ex->getPrice("SOL/USDT");
        cout << lastPrice << endl;
        double profit = ex->getProfit(0.3213, 121.75, lastPrice);
        double profit100 = ex->getProfitPercent(0.3213, 121.75, lastPrice);
        cout << setprecision(12) << profit << " (" << profit100 << "%)" << endl;
    } else {
        std::cerr << "Exchange no válido" << std::endl;
    }
    return 0;
}