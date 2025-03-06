#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void handleInterrupt(int sig)
{
    signal(SIGINT,handleInterrupt);
    printf("Jumped to interrupt handler\n");
    fflush(stdout);
}
int main() {

    
    signal(SIGINT,handleInterrupt);
    printf("Sleep #1\n");
    fflush(stdout);
    sleep(1);
    printf("Sleep #2\n");
    printf("^CJumped to interrupt handler\n");
    fflush(stdout);
    sleep(1);
    printf("Sleep #3\n");
    fflush(stdout);
    sleep(1);
    printf("Sleep #4\n");
    fflush(stdout);
    sleep(1);
    printf("Sleep #5\n");
    fflush(stdout);
    sleep(1);
    printf("Program exiting\n");
    exit(0);
}
