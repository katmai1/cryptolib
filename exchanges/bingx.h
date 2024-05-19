#ifndef BINGX_H
#define BINGX_H

#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

#include "../cryptolib.h"


using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;

class BingxAPI : public Exchange {

public:
    BingxAPI() : base_url("https://open-api.bingx.com") {}

    double _getPrice(const string symbol, const string quote) override {
        string market = symbol + "-" + quote;
        http_client client(base_url);
        uri_builder builder("/openApi/swap/v1/ticker/price");
        builder.append_query("symbol", market);

        try {
            http_response response = client.request(methods::GET, builder.to_string()).get();
            auto jsonResponse = response.extract_json().get();

            if (jsonResponse["data"].is_null()) {
                std::cerr << "Error: " << "This market no exist: " << market << std::endl;
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

#endif // BINGX_H