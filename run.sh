#!/usr/bin/bash

g++ -std=c++11 -o main main.cpp -lcpprest -lboost_system -lssl -lcrypto -lpthread -lboost_thread

./main