#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void main() {
int status = 0;
int pid = fork();
if (pid) {
printf("The parent process has started waiting.\n");
fflush(stdout);
wait(&status);
} else {
printf("The child process is going to sleep for 5 seconds.\n");
sleep(5);
printf("The child process has finished sleeping.\n");
status = 1;
exit(0);
}
printf("The parent process has finished waiting.\n");
exit(0);
}
