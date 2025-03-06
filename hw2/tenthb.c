#include <stdio.h>
#include <unistd.h>

#define MSGSIZE 16
int main() {
    int pfd[2];
    int retval;
    char msg[MSGSIZE];
    char buffer[MSGSIZE];
    pid_t pid;

    retval = pipe(pfd);
    if (retval == -1) {
        printf("Failed to create pipe\n");
        exit(1);
    }
    pid = fork();
    if (pid < 0) {
        printf("Failed to fork process\n");
        exit(1);
    } else if (pid == 0) {
        for (int i = 1; i <= 4; i++) {
            read(pfd[0], buffer, MSGSIZE);
            printf("This is the child process (process ID %d). Reading message 
            number %d from the pipe. Content is: %s\n", getpid(), i, buffer);
        }
    } else {
        for (int i = 1; i <= 4; i++) {
            printf("This is the parent process (process ID %d). Writing message 
            number %d to the pipe.\n", getpid(), i);
            snprintf(msg, MSGSIZE, "Message %d", i);
            write(pfd[1], msg, MSGSIZE);
        }
    }
    exit(0);
}
