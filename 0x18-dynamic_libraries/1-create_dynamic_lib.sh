#!/bin/bash

gcc *c -c
gcc *.o -shared -o liball.so
rm *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
