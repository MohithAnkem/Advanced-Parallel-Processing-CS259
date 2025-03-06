#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#define MSGSIZE 1
int count = 0;
void alarm_handler(int sig) {
    printf("Write blocked after %d characters.\n", count);
    exit(0);
}
int main() {
    int pfd[2], retval;
    retval = pipe(pfd);
    if (retval == -1) {
        printf("Failed to create pipe\n");
        exit(1);
    }
    signal(SIGALRM, alarm_handler);
    while (1) {
        char msg[MSGSIZE] = "a";
        alarm(3);
        int written = write(pfd[1], msg, MSGSIZE);
        if (written != -1) {
            count++;
        }
        alarm(0);

        if (count % 1024 == 0) {
            printf("%d characters in pipe\n", count);
            fflush(stdout);
        }
    }
    exit(0);
}
