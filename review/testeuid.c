#include <stdio.h>
#include <unistd.h>

int main() {
    // 获取并打印进程ID（PID）
    printf("Process ID: %d\n", getpid());

    // 获取并打印父进程ID（PPID）
    printf("Parent Process ID: %d\n", getppid());

    // 获取并打印用户ID（UID）
    printf("User ID: %d\n", getuid());

    // 获取并打印有效用户ID（EUID）
    printf("Effective User ID: %d\n", geteuid());
sleep(300);
    return 0;

}