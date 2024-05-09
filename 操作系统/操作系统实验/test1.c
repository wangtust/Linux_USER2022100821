// 引入输入输出相关的头文件
#include <stdio.h>
// 引入IPC（Inter-Process Communication，进程间通信）相关的头文件
#include <sys/ipc.h>
// 引入共享内存相关的头文件
#include <sys/shm.h>
// 引入字符串操作相关的头文件
#include <string.h>

// 定义共享内存的键值
#define SHM_KEY 1234
// 定义共享内存的大小
#define SHM_SIZE 1024

int main() {
    // 创建一个共享内存区域
    // SHM_KEY是共享内存的键值
    // SHM_SIZE是共享内存的大小
    // IPC_CREAT | 0666表示如果共享内存不存在则创建，且权限为0666（即用户、组和其他都可读写）
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    // 如果shmget返回-1，表示出错
    if (shmid == -1) {
        // 打印错误信息
        perror("shmget failed");
        // 返回1表示程序异常退出
        return 1;
    }

    // 将共享内存区域附加到进程的地址空间
    // shmid是共享内存的标识符
    // NULL表示让系统选择共享内存的地址
    // 0表示共享内存可读写
    char *shmaddr = shmat(shmid, NULL, 0);
    // 如果shmat返回-1，表示出错
    if (shmaddr == (char *)-1) {
        // 打印错误信息
        perror("shmat failed");
        // 返回1表示程序异常退出
        return 1;
    }

    // 将一条消息复制到共享内存区域
    strcpy(shmaddr, "Hello, world!");

    // 将共享内存区域从进程的地址空间分离
    shmdt(shmaddr);
/*这一步是将共享内存区域从当前进程的地址空间分离。
当一个进程完成了对共享内存的使用后，它应该将共享内存从自己的地址空间中分离，以释放资源。
在这段代码中，`shmdt(shmaddr);`这一行的作用就是将之前通过`shmat`函数附加到当前
进程地址空间的共享内存区域分离出来。`shmaddr`是共享内存的起始地址，是`shmat`函数的返回值。
这并不会删除共享内存区域，只是将其从当前进程的地址空间中移除。
共享内存区域仍然存在，直到使用`shmctl`函数显式删除它，或者系统重启。
其他已经附加了这个共享内存区域的进程仍然可以继续使用它。*/
    // 返回0表示程序正常退出
    return 0;
}