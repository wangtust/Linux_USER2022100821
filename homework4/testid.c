#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("pid:%d, ppid:%d, uid:%d, gid:%d\n", getpid(), getppid(), getuid(), getgid());
	return 0;
}
