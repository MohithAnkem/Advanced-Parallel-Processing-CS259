#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    printf("Immediately before the fork. Only one process at this point.\n");
    fflush(stdout);  

    pid = fork();

    printf("Immediately after the fork. This statement should print twice.\n");
    fflush(stdout);  

    if (pid < 0) {
         
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
         
        printf("I'm the child. My pid is %d. My parent's pid is %d.\n", getpid(), getppid());
    } else {
         
        printf("I'm the parent. My pid is %d. My child's pid is %d.\n", getpid(), pid);
        //wait(NULL);   
    }

    return 0;
}