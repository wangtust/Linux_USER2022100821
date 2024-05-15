#include <sys/types.h>
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
        perror("open the 1.txt");
        return 1;
    }
   int ret=dup2(fd, 1); // 注解1  让本来指向标准输出缓冲区的描述符1指向文件1.txt
      printf("where am I?\n"); //向输出缓冲区写入数据
      close(fd);
      return 0;

}
