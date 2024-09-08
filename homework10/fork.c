#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t fpid = -1;
    int count =0;
    fpid=fork();
printf("fpid=%d,count=%d\n",fpid,count);

    if (fpid == 0) {
        count+=1;
    } else {
        count+=3;
    
        sleep(5);}

        // 父进程执行的代码
        printf("ppid=%d ,fpid=%d,count= %d\n", getppid(),fpid,count);
    

    return 0;
}