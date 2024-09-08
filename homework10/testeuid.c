#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // 获取当前进程的PID
    pid_t pid = getpid();
    // 获取当前进程的父进程PID
    pid_t ppid = getppid();
    // 获取当前用户的用户ID
    uid_t uid = getuid();
    // 获取当前用户的有效用户ID
    uid_t euid = geteuid();

    printf("PID: %d\n", pid);
    printf("PPID: %d\n", ppid);
    printf("UID: %d\n", uid);
    printf("EUID: %d\n", euid);

    return 0;
}