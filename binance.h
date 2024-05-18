#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;

class BinanceAPI {
public:
    BinanceAPI() : base_url("https://api.binance.com/api/v3") {}

    double getPrice(const string& symbol) {
        http_client client(base_url);
        uri_builder builder(U("/ticker/price"));
        builder.append_query(U("symbol"), utility::conversions::to_string_t(symbol));

        // Realizar solicitud GET
        auto response = client.request(methods::GET, builder.to_string()).get();

        // Verificar si la solicitud fue exitosa
        if (response.status_code() == status_codes::OK) {
            // Leer el cuerpo de la respuesta como JSON
            auto jsonValue = response.extract_json().get();

            // Obtener el precio del símbolo desde la respuesta JSON
            utility::string_t priceStr = jsonValue[U("price")].as_string();
            cout << priceStr << endl;
            double price = std::stod(utility::conversions::to_string_t(priceStr));    
            return price;
        } else {
            throw runtime_error("Error al obtener respuesta del servidor");
        }
    }

private:
    const string base_url;
};