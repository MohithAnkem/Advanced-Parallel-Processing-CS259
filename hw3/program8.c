#include <stdio.h>
#include <omp.h>
#include <time.h>

long long num_steps = 1000000000;
double step;

int main(int argc, char* argv[])
{
	double x, pi, sum=0.0;
	int i;
	step = 1./(double)num_steps;
    clock_t start_time = clock();

	for (i=0; i<num_steps; i++)
	{
		x = (i + .5)*step;
		sum = sum + 4.0/(1.+ x*x);
	}
	clock_t end_time = clock();
    double sequential_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	pi = sum*step;

	printf("The value of PI is %15.12f \n",pi);
    printf("Sequential execution time: %f seconds\n", sequential_time);

}
