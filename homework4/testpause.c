#include <signal.h>
#include <stdio.h>
#include <unistd.h>
 
void mysignal(int sig)
{
	printf("\n I got signal %d \n", sig );   //  显示捕获的信号
}
 
int main()
{
	//改变终端中断信号SIGUSR1的默认行为，使之执行 mysignal函数
	signal(SIGUSR1, mysignal);   
	while(1)
	{
		printf("Hello World!\n");
		pause();   // 让自己睡眠，等信号发生
	}
	return 0;
}
