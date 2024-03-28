#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/wait.h>
int main() {
    pid_t pid1, pid2;
    int status;
    pid1 = fork();
    if (pid1 < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid1 == 0) {
        // 子进程
        for (int i = 0; i < 10;i++)
            printf("daughter\n");
    } else {
        wait(&status);
        pid2 = fork();
        if (pid2 < 0) {
            fprintf(stderr, "Fork failed");
            return 1;
        }

        if (pid2 == 0) {
            // 子进程
        for (int i = 0; i < 10;i++)
            printf("son\n");
        } else {
            wait(&status);
            // 父进程
            for (int i = 0; i < 10; i++)
                printf("parent\n");
        }
    }

    return 0;
}