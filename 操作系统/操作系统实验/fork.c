#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid1 == 0) {
        // 子进程
        printf("b\n");
    } else {
        pid2 = fork();
        if (pid2 < 0) {
            fprintf(stderr, "Fork failed");
            return 1;
        }

        if (pid2 == 0) {
            // 子进程
            printf("c\n");
        } else {
            // 父进程
            printf("a\n");
        }
    }

    return 0;
}