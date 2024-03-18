#include <stdio.h>
#include <unistd.h>
#include <string.h>
void main()
{
char *data="Hello World !\n";
printf("pid=%d, main address:%p,  data address:%p data:%s\n",getpid(),main,data,data);
write(2, data, strlen(data));
}