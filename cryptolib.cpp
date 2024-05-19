#include <memory>
#include <sstream>

#include "cryptolib.h"

#include "exchanges/binance.h"
#include "exchanges/kucoin.h"


unique_ptr<Exchange> getExchange(const string& exchange) {
    if(exchange == "binance") { return unique_ptr<Exchange>(new BinanceAPI());  }
    else if (exchange == "kucoin") {    return unique_ptr<Exchange>(new KucoinAPI());  }
    else {  return nullptr; }
}