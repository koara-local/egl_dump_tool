#!/bin/bash

g++ -shared -fPIC -std=c++11 ./test.cpp -ldl -I./include
