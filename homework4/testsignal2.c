#include <signal.h>
#include <stdio.h>
#include <unistd.h>
 
void mysignal(int sig)
{
	printf("\n I got signal %d \n", sig );   //  显示捕获的信号

(void) signal(SIGINT, SIG_DFL);     //  注解1
}
 
int main()
{
	
	signal(SIGINT, mysignal);  // i注解 2 
	while(1)
	{
		printf("Hello World!\n");
		sleep(10);   // 睡眠10秒 
	}
	return 0;
}
/*你的理解基本正确，但是有一点需要澄清：`signal` 函数本身并不会“接收”或“处理”信号。它的作用是设置信号的处理函数。当操作系统向你的程序发送信号时，操作系统会调用你为该信号设置的处理函数。

下面是你的程序的执行过程：

1. 当你的程序启动时，`main` 函数中的 `signal(SIGINT, mysignal);` 这行代码将 SIGINT 信号的处理函数设置为 `mysignal`。

2. 然后，你的程序进入一个无限循环，在每次循环中，它打印 "Hello World!"，然后暂停执行 10 秒。

3. 当你在终端中运行 `kill -SIGINT` 命令时，操作系统会向你的程序发送 SIGINT 信号。因为你已经将 SIGINT 信号的处理函数设置为 `mysignal`，所以操作系统会调用 `mysignal` 函数。

4. 在 `mysignal` 函数中，`printf("\n I got signal %d \n", sig);` 这行代码会打印 "I got signal "，后面跟着信号的编号（在大多数系统中，SIGINT 的编号是 2）。

5. 然后，`signal(SIGINT, SIG_DFL);` 这行代码将 SIGINT 信号的处理函数设置为默认的处理函数。这意味着，如果你的程序再次接收到 SIGINT 信号，它会执行默认的处理函数，而不是 `mysignal` 函数。

6. `mysignal` 函数结束后，你的程序会回到无限循环，继续打印 "Hello World!"，然后暂停执行 10 秒。

请注意，`signal` 函数只是设置信号的处理函数，它并不会等待信号的到来。当你的程序接收到信号时，操作系统会立即调用相应的处理函数，无论你的程序当前正在做什么。*/