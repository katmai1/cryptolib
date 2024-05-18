#include <iostream>
#include "binance.h"


using namespace std;


int main() {
   BinanceAPI binance;

    try {
        // Obtener el precio de Bitcoin en dólares estadounidenses (USDT)
        double bitcoinPrice = binance.getPrice("BTCUSDT");
        cout << "Precio de Bitcoin (USDT): $" << bitcoinPrice << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}