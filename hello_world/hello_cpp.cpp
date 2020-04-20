#include <iostream>

static const int N = 4;

int main(){
    //# Memory Allocation
    float *data = (float*)malloc(sizeof(float)*N);

    //# Initialization
    for(int i=0; i<N; i++) data[i] = i;

    //# Serial Computation
    for(int i=0; i<N; i++) data[i] *= 2;

    //# Print Output
    for(int i=0; i<N; i++) std::cout << data[i] << std::endl;

    free(data);
    return 0;
}
