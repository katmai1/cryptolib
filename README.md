# cryptolib
Library to manage exchanges

## Requeriments

sudo apt-get install libcurl4-openssl-dev

git clone https://github.com/microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg integrate install
./vcpkg/vcpkg install nlohmann-json


## compile 
g++ -std=c++11 -o main main.cpp -lcpprest -lboost_system -lssl -lcrypto -lpthread -lboost_thread