#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handleAlarm()
{
    printf("\n Timeout reached. Exciting program. \n");
    exit(0);
}

int main()
{
    signal(SIGALRM, handleAlarm);

    printf("Enter input - Time Limit: 10 seconds\n");
    fflush(stdout);
    alarm(10);

    char input[100];
    gets(input);
    alarm(0);

    printf("User entered: %s\n", input);
    exit(0);
}