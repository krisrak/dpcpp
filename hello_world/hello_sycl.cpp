#include <CL/sycl.hpp>
using namespace cl::sycl;

static const int N = 4;

int main(){
    //# define queue which has default device associated for offload
    queue q;
    std::cout << "Device: " << q.get_device().get_info<info::device::name>() << std::endl;

    //# Memory Allocation
    float *data = (float*)malloc(sizeof(float)*N);
    
    //# Initialization
    for(int i=0; i<N; i++) data[i] = i;

    //# Create buffer
    buffer<float> data_buffer(data, range<1>(N));

    //# Submit command groups to GPU device
    q.submit([&](handler &h){
        //# Create accessor to copy buffer to device
        auto DATA = data_buffer.get_access<access::mode::read_write>(h);
        
        //# Parallel Computation on device
        h.parallel_for<class kernel_doubler>(range<1>(N), [=] (id<1> i){
            DATA[i] *= 2;
        });
    });
 
    //# Update buffer on host
    data_buffer.get_access<access::mode::read>();
    
    //# Print Output
    for(int i=0; i<N; i++) std::cout << data[i] << std::endl;

    free(data);
    return 0;
}
