# What is Data Parallel C++ ?
- Data Parallel C++ (DPC++) is a __unified programming language__ that enables programming for __diverse architectures__ like CPU, GPU, FPGA and other accelerators. 
- DPC++ is based on __industry standards__ and __open specification__. 
- DPC++ = __C++__ and __SYCL__* standard and extensions. 
- DPC++ simplifies __expressing parallelism__.

# Hello World for DPC++
Comparing a simple example implemented in C++, SYCL and DPC++

## Sample Code
The code sample does the following:
- __allocate__ an array
- __initialize__ the array to some value
- do __computation__ on each element of array (multiply by 2)
- __print output__ data array

## C++ Implementation
C++ implementation of the sample code which uses a __for-loop__ to do computation and all code runs on CPU

[hello_cpp.cpp](hello_cpp.cpp)

## SYCL Implementation
Same sample code as C++, but submits the computation to accelerator device using __sycl::queue__ and uses sycl __buffer & accessors__ for data management.

[hello_sycl.cpp](hello_sycl.cpp)

## DPC++ Implementation 
Same sample code as C++, but submits the computation to accelerator device using sycl::queue with __DPC++ simplification__ and uses __Unified Shared Memory__ (USM) for data management.

[hello_dpcpp.cpp](hello_dpcpp.cpp)
