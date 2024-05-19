#!/usr/bin/bash

g++ -std=c++11 -o main main.cpp cryptolib.cpp -lcpprest -lboost_system -lssl -lcrypto -lpthread -lboost_thread

./main