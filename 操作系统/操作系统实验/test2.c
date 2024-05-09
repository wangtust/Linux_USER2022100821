// 引入输入输出相关的头文件
#include <stdio.h>
// 引入IPC（Inter-Process Communication，进程间通信）相关的头文件
#include <sys/ipc.h>
// 引入共享内存相关的头文件
#include <sys/shm.h>

// 定义共享内存的键值
#define SHM_KEY 1234
// 定义共享内存的大小
#define SHM_SIZE 1024

int main() {
    // 获取一个已存在的共享内存区域的标识符
    // SHM_KEY是共享内存的键值
    // SHM_SIZE是共享内存的大小
    // 0666是共享内存的权限，表示用户、组和其他都可读写
    int shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
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

    // 从共享内存区域读取数据并打印
    printf("Data received from shared memory: %s\n", shmaddr);

    // 将共享内存区域从进程的地址空间分离
    shmdt(shmaddr);

    // 删除共享内存区域
    // shmid是共享内存的标识符
    // IPC_RMID是删除共享内存的命令
    // NULL表示不需要额外的参数
    shmctl(shmid, IPC_RMID, NULL);

    // 返回0表示程序正常退出
    return 0;
}

