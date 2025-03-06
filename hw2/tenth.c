#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 16

int main() {
    int pfd[2];
    int retval;

    char msg[MSGSIZE];
    char buffer[MSGSIZE];

    retval = pipe(pfd);
    if (retval == -1) {
        printf("Failed to create pipe\n");
        exit(1);
    }

    for (int i = 1; i < 5; i++) {
        snprintf(msg, MSGSIZE, "Message %d", i);
        printf("Writing %s\n", msg);
        write(pfd[1], msg, MSGSIZE);
    }

    for (int i = 1; i < 5; i++) {
        read(pfd[0], buffer, MSGSIZE);
        printf("Read %s\n", buffer);
    }

    exit(0);
}
