#ifndef BINANCE_H
#define BINANCE_H

#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

#include "../cryptolib.h"


using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;

class BinanceAPI : public Exchange {

public:
    BinanceAPI() : base_url("https://api.binance.com/api/v3") {}

    double _getPrice(const string symbol, const string quote) override {
        string market = symbol + quote;
        http_client client(base_url);
        uri_builder builder("/ticker/price");
        builder.append_query("symbol", market);

        auto response = client.request(methods::GET, builder.to_string()).get();
        auto jsonValue = response.extract_json().get();

        if (response.status_code() == status_codes::OK) {
            string priceStr = jsonValue["price"].as_string();
            cout << priceStr << endl;
            double price = stod(priceStr);    
            return price;
        }
        else {
            throw runtime_error(jsonValue["msg"].as_string());
        }
    }

private:
    const string base_url;
};

#endif // BINANCE_H