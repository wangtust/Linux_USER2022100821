#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 256
#define MAXARGS 30

int main(void) {
    char buf[MAXLINE];
    char *argv[MAXARGS];
    pid_t fpid;
    int status;

    printf("%d%% ", getpid());

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        buf[strlen(buf) - 1] = 0;  // replace newline with null

        // Split buf into words and store them in argv
        int i = 0;
        argv[i] = strtok(buf, " ");
        while (argv[i] != NULL) {
            i++;
            argv[i] = strtok(NULL, " ");
        }

        if ((fpid = fork()) < 0) {
            return -1;  // fork error
        } else if (fpid == 0) {  // child
            execvp(argv[0], argv);
            printf("fpid=%d,ppid=%d,pid=%d,couldn't execute: %s\n", fpid, getppid(), getpid(), buf);
            exit(-1);
        } else if (fpid > 0) {  // parent
            if ((waitpid(fpid, &status, 0)) < 0) {
                return -1;  // wait error
            }
            printf("fpid=%d,ppid=%d,pid=%d%% ", fpid, getppid(), getpid());
        }
    }

    return 0;
}