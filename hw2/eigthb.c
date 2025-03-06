#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    signal(SIGINT, SIG_IGN);
    printf("Sleep #1\n");
    fflush(stdout);
    sleep(1);
    printf("Sleep #2\n");
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
