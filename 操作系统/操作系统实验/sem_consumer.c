#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_SIZE 1024  // 定义共享内存的大小
#define SEM_KEY 1234  // 定义信号量的键值
#define SHM_KEY 5678  // 定义共享内存的键值

// 定义信号量联合体，用于信号量操作
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    // 获取已存在的信号量
    int semid = semget(SEM_KEY, 1, 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // 获取已存在的共享内存
    int shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // 将共享内存附加到当前进程的地址空间
    char *data = shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // 定义信号量操作结构体
    struct sembuf sb = {0, -1, 0};
    char last_received[SHM_SIZE] = {0};
    do {
        // 执行P操作，尝试获取资源
        semop(semid, &sb, 1);
        // 如果共享内存中的数据与上次接收的数据不同，则打印并保存新数据
        if (strcmp(data, last_received) != 0) {
            printf("Received: %s", data);
            strcpy(last_received, data);
        }
        // 执行V操作，释放资源
        sb.sem_op = 1;
        semop(semid, &sb, 1);
    } while (strcmp(data, "quit\n") != 0);  // 当共享内存中的数据为"quit\n"时，退出循环

    // 将共享内存从当前进程的地址空间中分离
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}