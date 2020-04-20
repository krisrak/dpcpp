#include <CL/sycl.hpp>
using namespace sycl;

static const int N = 4;

int main(){
    //# define queue which has default device associated for offload
    queue q;
    std::cout << "Device: " << q.get_device().get_info<info::device::name>() << std::endl;

    //# USM Allocation enables data access on host and device
    float *data = static_cast<float*>(malloc_shared(N * sizeof(float), q));

    //# Initialization
    for(int i=0; i<N; i++) data[i] = i;

    //# Offload parallel computation to GPU device
    q.parallel_for(range<1>(N), [=] (id<1> i){
        data[i] *= 2;
    }).wait();

    //# Print Output
    for(int i=0; i<N; i++) std::cout << data[i] << std::endl;

    free(data, q);
    return 0;
}
