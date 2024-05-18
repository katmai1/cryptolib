#include <iostream>
#include <iomanip>
#include "binance.h"


using namespace std;


int main() {
   BinanceAPI binance;

    try {
        // Obtener el precio de Bitcoin en dólares estadounidenses (USDT)
        double bitcoinPrice = binance.getPrice("CHZUSDT");
        cout << setprecision(15) << bitcoinPrice << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}