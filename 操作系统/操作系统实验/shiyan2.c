#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
// we can use the if-else structure to control the process to execute which code
int pid1,pid2;

pid1 = fork();

if(pid1<0)
{
    // means we failed to creat a process
    printf("failed");
}
else if(pid1>0)  //父亲
{
    // the father process execute these codes
    pid2 = fork();  // spawn the other child process c
    //nested if-else structure
        if(pid2<0)
        {
            printf("failed");
        }
        else if(pid2==0)
        {
            for(int i=0;i<10;i++)
            {
                printf("daughter\n");
            }
            printf("我是子进程2---c\n");
        }
        else //pid2>0 说明是父进程
        {   
            for(int i=0;i<10;i++)
            {
                printf("father\n");
            }
            printf("我是父进程---a\n");
        }

}
else  //pid1 == 0 说明是第一个子进程
{
    // means pid==0 we let the first child process to execute these codes
    for(int i=0;i<10;i++)
            {
                printf("son\n");
            }
    printf("我是子进程1---b\n");
}



}

