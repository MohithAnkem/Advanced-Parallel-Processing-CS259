#include <stdio.h>
#include <omp.h>
#include <time.h>

long long num_steps = 1000000000;  // Number of iterations (1 billion)
double step;

int main() {
    double x, pi, sum = 0.0;
    int i;
    int NTHREADS[] = {2, 4, 8, 16, 32};  // Different thread counts for experimentation
    int num_thread_sizes = sizeof(NTHREADS) / sizeof(NTHREADS[0]);  // Calculate the size of the array

    step = 1.0 / (double)num_steps;

    // Loop over the different thread counts
    for (int t = 0; t < num_thread_sizes; t++) {
        // Set the number of threads to NTHREADS[t]
        omp_set_num_threads(NTHREADS[t]);

        // Start time for parallel execution with current number of threads
        clock_t start_time = clock();

        sum = 0.0;  // Reset sum for each run

        // Parallel Pi calculation with OpenMP
        #pragma omp parallel for reduction(+:sum) private(x)
        for (i = 0; i < num_steps; i++) {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }

        pi = sum * step;

        // End time for parallel execution
        clock_t end_time = clock();
        double parallel_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("With %d threads, Pi = %15.12f\n", NTHREADS[t], pi);
        printf("Execution time with %d threads: %f seconds\n\n", NTHREADS[t], parallel_time);
    }

    return 0;
}
