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
    int val;  // 用于SETVAL操作
    struct semid_ds *buf;  // 用于IPC_STAT和IPC_SET操作
    unsigned short *array;  // 用于GETALL和SETALL操作
};

int main() {
    // 创建或获取信号量
    int semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // 初始化信号量的值为1
    union semun arg;
    arg.val = 1;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl");
        exit(1);
    }

    // 创建或获取共享内存
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
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
    struct sembuf sb = {0, -1, 0};  // 第一个参数是信号量的索引，第二个参数是操作的数量，第三个参数是操作的标志
    char input[100];
    do {
        // 从标准输入读取数据
        printf("Enter some text: ");
        fgets(input, 100, stdin);
        // 执行P操作，尝试获取资源
        semop(semid, &sb, 1);  // 第一个参数是信号量的标识符，第二个参数是指向信号量操作结构体的指针，第三个参数是操作的数量
        // 将数据复制到共享内存
        strcpy(data, input);
        // 执行V操作，释放资源
        sb.sem_op = 1;
        semop(semid, &sb, 1);
    } while (strcmp(input, "quit\n") != 0);  // 当输入为"quit\n"时，退出循环

    // 将共享内存从当前进程的地址空间中分离
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    // 删除共享内存
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    // 删除信号量
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(1);
    }

    return 0;
}