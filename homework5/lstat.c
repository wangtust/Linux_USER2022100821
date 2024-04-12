#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // 检查是否提供了文件路径参数
    if(argc < 2){
        printf("\n\tusage:");
        printf("\n\t\t%s filepath\n", argv[0]);
        return -1;
    }

    struct stat tmp;  // 定义一个stat结构体来存储文件状态信息
    char* res;  // 用来存储文件类型的字符串
    int ret;  // 用来存储lstat函数的返回值

    // 调用lstat函数获取文件状态信息，结果存储在tmp中
    ret = lstat(argv[1], &tmp);

    // 使用一系列的宏来检查文件类型
    if(S_ISREG(tmp.st_mode))
        res = "regular";  // 普通文件
    else if(S_ISDIR(tmp.st_mode))
        res = "directory";  // 目录
    else if(S_ISBLK(tmp.st_mode))
        res = "block";  // 块设备
    else if(S_ISCHR(tmp.st_mode))
        res = "character";  // 字符设备
    else if(S_ISLNK(tmp.st_mode))
        res = "link";  // 符号链接
    else if(S_ISFIFO(tmp.st_mode))
        res = "fifo";  // FIFO（命名管道）
    else if(S_ISSOCK(tmp.st_mode))
        res = "socket";  // 套接字
    else
        res = "unknown";  // 未知类型

    // 打印lstat函数的返回值和文件类型
    printf("ret:%d, %s : %s\n",ret, argv[1], res);

    return 0;
}