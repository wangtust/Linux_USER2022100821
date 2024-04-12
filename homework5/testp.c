#include <stdio.h>
#include <unistd.h>
#include<signal.h>
extern char** environ;

void handler(int n)   //自定义函数，用于收到信号, 继续运行程序
{
    printf("get signal  USR1， test prg continue \n");
}

int main(int argc,char *argv[])
{
int i;
    signal(SIGUSR1,handler); // 设置信号SIGUSR1 处理程序
       for (i=0; argv[i]!=NULL; ++i)
        printf("argv[%d]=%s\n", i,argv[i]);
       for (i=0; environ[i]!=NULL; ++i)
        printf("environ[%d]=%s\n",i, environ[i]);
	printf("test prg, %s,  pid:%d, ppid:%d, euid:%d\n", argv[0],getpid(), getppid(), geteuid());
//    sleep(15);   //进程睡眠15秒
   pause();   //  让自己睡眠 （通过 信号 可以唤醒）
	printf("test prg end. \n");
    return(0);  //  返回，即结束当前进程
}
