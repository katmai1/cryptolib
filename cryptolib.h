#ifndef CRYPTOLIB_H
#define CRYPTOLIB_H

#include <iostream>
#include <memory>
#include <sstream>


using namespace std;

class Exchange {

public:
    virtual ~Exchange() = default;

    // parsea el market y llama a la funcion interna que consulta el precio
    virtual double getPrice(const string& market) {
        string symbol, quote;
        istringstream iss(market);
        getline(iss, symbol, '/');
        getline(iss, quote);
        return _getPrice(symbol, quote);
    };

    // ************************************************************************
    // funciones que hay que sobrescribir en cada exchange
    virtual double _getPrice(const string symbol, const string quote) { return 0;   }
};


// ************************************************************************
// funciona principal que devuelve subclase del exchange solicitado
unique_ptr<Exchange> getExchange(const string& exchange);

#endif // CRYPTOLIB_H