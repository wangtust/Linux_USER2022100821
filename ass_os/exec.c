#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();  // 创建新进程

    if (pid == 0) {  // 子进程
        char *argv[] = {"ls", "-l", NULL};
        execvp("ls", argv);  // 用新的程序替换子进程
    } else if (pid > 0) {  // 父进程
        // 父进程可以继续执行其他任务
    } else {  // fork 失败
         perror("fork failed");  // 打印错误消息
    exit(1);  // 退出程序
    }

    return 0;
}