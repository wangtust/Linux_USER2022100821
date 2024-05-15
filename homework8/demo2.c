#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
 
int main(void)
{
    int fd=open("./1.txt",O_RDWR|O_CREAT,0644);
    if(fd<0)
    {
        perror("cannot open the 1.txt");
        return 1;
    }
//     int ret=dup2(fd, 0); // 让本来指向标准入缓冲区的描述符0指向文件1.txt
  
     char buf[128]="";
     gets(buf);  // 从输入缓冲区读取数据
     puts(buf);
 
     close(fd);

     return 1;
}
