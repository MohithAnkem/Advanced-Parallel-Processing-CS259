#include <stdio.h>
#include <omp.h>

int main() {
    int i, sum = 0;
    int COUNT = 1000;  
    int NTHREADS = 32; 

    omp_set_num_threads(NTHREADS);

    #pragma omp parallel for
    for (i = 0; i < COUNT; i++) {
        sum = sum + i;
        printf("Thread number: %d Iteration: %d Local Sum: %d\n",
               omp_get_thread_num(), i, sum);
    }

    printf("\nAll Threads Done – Final Global Sum: %d\n\n", sum);
    return 0;
}
