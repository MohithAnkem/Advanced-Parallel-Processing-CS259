#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
int pid, pid2, pid3, pid4;
int Apid, Bpid;
printf("Immediately before the fork. Only one process at this point.\n");
fflush(stdout);
pid = fork();
if (pid > 0) {
printf("node A. Pid is %d\n", getpid());
fflush(stdout);
Apid = getpid();
wait(NULL);
} else if (pid == 0) {
printf("\tnode B. Pid is %d, parent's pid is %d\n", getpid(), getppid());
fflush(stdout);
Bpid = getpid();
} else
printf("Failed to fork\n");
pid2 = fork();
if (pid2 > 0)
wait(NULL);
else if (pid2 == 0 && getppid() == Bpid) {
printf("\t\tnode D. Pid is %d, parent's pid is %d\n", getpid(), getppid());
fflush(stdout);
} else if (pid2 == 0 && getppid() == Apid) {
printf("\tnode C. Pid is %d, parent's pid is %d\n", getpid(), getppid());
fflush(stdout);
pid3 = fork();
if (pid3 == 0) {
printf("\t\tnode E. Pid is %d, parent's pid is %d\n", getpid(),
getppid());
fflush(stdout);

} else if (pid3 > 0) {
pid4 = fork();
if (pid4 == 0)
printf("\t\tnode F. Pid is %d, parent's pid is %d\n", getpid(),
getppid());
fflush(stdout);
if (pid4 > 0)
wait(NULL);
}
}
exit(0);
}
