#include <stdio.h>

int main() {
    #pragma omp parallel
    {
        printf("Hello ");
    }
    printf("\n\nGoodBye - Team Destroyed - Exiting Program\n\n");
}
