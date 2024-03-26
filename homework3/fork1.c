#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int glob1=5;
int main(int argc, char *argv[])
{
int sum;
int ret_pid;
    ret_pid = fork();     // 第一个  fork
    ret_pid = fork();   //第二个 fork
printf("\n ppid=%d, pid=%d,  ret_pid=%d \n",getppid(),getpid(),ret_pid);

    sleep(30);  pause();
    return 0;
}
