#!/bin/bash
source /opt/intel/inteloneapi/setvars.sh > /dev/null 2>&1
dpcpp hello_simple_dpcpp.cpp
./a.out

