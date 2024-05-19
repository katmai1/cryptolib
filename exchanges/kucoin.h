#ifndef KUCOIN_H
#define KUCOIN_H

#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

#include "../cryptolib.h"


using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;

class KucoinAPI : public Exchange {

public:
    KucoinAPI() : base_url("https://api.kucoin.com") {}

    double _getPrice(const string symbol, const string quote) override {
        string market = symbol + "-" + quote;
        http_client client(base_url);
        uri_builder builder("/api/v1/market/orderbook/level1");
        builder.append_query("symbol", market);

        try {
            http_response response = client.request(methods::GET, builder.to_string()).get();
            auto jsonResponse = response.extract_json().get();

            if (jsonResponse["data"].is_null()) {
                std::cerr << "Error: " << "This market no existe: " << market << std::endl;
            }
            else {
                string priceStr = jsonResponse["data"]["price"].as_string();
                return stod(priceStr);
            }
        }
        catch (const exception& e) {    std::cerr << "Error: " << e.what() << std::endl;    }
        return 0;
    }

private:
    const string base_url;
};

#endif // KUCOIN_H