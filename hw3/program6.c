#include <stdio.h>
#include <omp.h>

int main() {
    int i;              // Loop variable
    int COUNT = 10;    // Change as required
    int NTHREADS = 8;   // Change as required
    int sum=0;
    omp_set_num_threads(NTHREADS);

    #pragma omp parallel for
    for (i = 0; i < COUNT; i++) {
        //int sum = 0;  // Declare 'sum' as a private variable inside the loop
        sum = sum + i;
        printf("Thread number: %d Iteration: %d Local Sum: %d\n",
               omp_get_thread_num(), i, sum);
    }

    printf("\nAll Threads Done - Final Global Sum: %d\n\n", sum);
    return 0;
}
