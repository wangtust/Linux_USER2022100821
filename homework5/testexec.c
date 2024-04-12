#include <stdio.h>
#include <unistd.h>
#include<signal.h>

void handler(int n)   // 自定义的信号处理函数，用于接收SIGUSR1信号
{
    printf("get signal  USR1， test exec continue \n");
}

int main(int argc,char *argv[])
{
    char *env_execve[]={"ONE=1","TWO=2", NULL};  // 要设置的环境变量
    char *argv_execve[]={"first","second", NULL};  // 要传递给新程序的命令行参数

    if (argc<2) {   // 检查是否提供了要执行的程序的路径
        printf("usage: testexec  prg \n");
        return(1);
    }

    signal(SIGUSR1,handler); // 注册SIGUSR1信号的处理函数

    printf("before exec,  pid:%d, ppid:%d, euid:%d\n", getpid(), getppid(), geteuid());  // 打印当前进程的信息

    pause();  // 暂停进程，等待信号

    // 调用execve函数执行程序
    if(execve(argv[1], argv_execve, env_execve)<0)
         perror("Err on execve");  // 如果execve函数返回，打印错误信息

    printf("after exec, pid:%d, ppid:%d, euid:%d\n", getpid(), getppid(), geteuid());  // 打印当前进程的信息

    return(0);
}