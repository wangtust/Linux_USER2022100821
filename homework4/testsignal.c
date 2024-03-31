#include <signal.h>
#include <stdio.h>
#include <unistd.h>
 
void mysignal(int sig)
{
	printf("\n I got signal %d \n", sig );   //  显示捕获的信号
// 恢复终端中断信号SIGINT的默认行为
//	(void) signal(SIGINT, SIG_DFL);     //  注解1
}
 
int main()
{
	//改变终端中断信号SIGINT的默认行为，使之执行 mysignal函数
	//而不是终止程序的执行
//	signal(SIGINT, mysignal);  // i注解 2 
	while(1)
	{
		printf("Hello World!\n");
		sleep(10);   // 睡眠10秒 
	}
	return 0;
}
