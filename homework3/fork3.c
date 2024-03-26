#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main ()
{
 pid_t fpid; //fpid表示fork函数返回的值
 int count=0;
 fpid=fork();
 if (fpid < 0)
   printf("error in fork!");
 else if (fpid == 0) {
   printf("  fpid=%d,pid=%d,ppid=%d\n",
            fpid,getppid(),getpid());
   count+=10;
 }
 else {
   printf(" fpid=%d,pid=%d,ppid=%d\n",
            fpid,getppid(),getpid());
   count+=20;
 }
 printf(" fpid=%d, count=%d\n",fpid,count);
 sleep(60);  pause();
}
