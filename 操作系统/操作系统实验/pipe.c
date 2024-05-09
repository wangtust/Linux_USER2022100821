#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/wait.h>

int main() {
    pid_t pid1, pid2;  // 子进程的进程ID
    int status;  // 子进程的状态
    int fd[2];  // 文件描述符数组，用于创建管道
    pipe(fd);  // 创建管道

    pid1 = fork();  // 创建第一个子进程
    if (pid1 < 0) {
        fprintf(stderr, "Fork failed");  // 如果fork失败，打印错误信息
        return 1;
    }

    if (pid1 == 0) {  // 子进程1
        close(fd[0]);  // 关闭读端，因为我们只向管道写入数据
        write(fd[1], "Child 1 is sending a message!\n", 30);  // 向管道写入数据
        return 0;  // 子进程结束
    } 
    else {  // 父进程
        wait(&status);  // 等待子进程结束
        //因为两个子进程都要在管道里写，但是只要父进程读取子进程2的内容，于是先设置缓冲区消去管道1写的
        char buf1[64];  // 缓冲区，用于存储从管道读取的数据
        int x;  // 用于存储read()函数的返回值，即读取的字节数
        while ((x = read(fd[0], buf1, sizeof(buf1)-1)) > 0) {  // 从管道读取数据，直到没有数据可读，这样就消除了子进程1写入的内容
            pid2 = fork();  // 创建第二个子进程
            if (pid2 < 0) {
                fprintf(stderr, "Fork failed");  // 如果fork失败，打印错误信息
                return 1;
            }

            if (pid2 == 0) {  // 子进程2
                close(fd[0]);  // 关闭读端，因为我们只向管道写入数据
                write(fd[1], "Child 2 is sending a message!\n", 30);  // 向管道写入数据
                return 0;  // 子进程结束
            } 
            else {  // 父进程
                wait(&status);  // 等待子进程结束
                close(fd[1]);  // 父进程关闭写入端，因为我们只从管道中读取数据

                char buf[64];  // 缓冲区，用于存储从管道读取的数据
                int n;  // 用于存储read()函数的返回值，即读取的字节数
                while ((n = read(fd[0], buf, sizeof(buf)-1)) > 0) {  // 从管道读取数据，直到没有数据可读
                    buf[n] = 0;  // 在字符串末尾添加null字符，以确保它是一个有效的C字符串
                    printf("%s", buf);  // 打印从管道读取的数据
                }
            }
        }
        return 0;
    }
}