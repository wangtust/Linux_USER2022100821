#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    key_t key = 1234; // 信号量键
    int semid; // 信号量ID
    union semun arg;
    struct sembuf sb = {0, -1, 0}; // 减少信号量的操作

  // 创建信号量
if ((semid = semget(key, 1, IPC_CREAT | 0666)) == -1) {
    perror("semget");
    exit(1);
} else {
    printf("Semaphore created with id: %d\n", semid);
}

// 初始化信号量
arg.val = 1;
if (semctl(semid, 0, SETVAL, arg) == -1) {
    perror("semctl");
    exit(1);
} else {
    printf("Semaphore value set to: %d\n", arg.val);
}

// 执行PV操作
if (semop(semid, &sb, 1) == -1) {
    perror("semop");
    exit(1);
} else {
    int sem_val = semctl(semid, 0, GETVAL);
    if (sem_val == -1) {
        perror("semctl");
        exit(1);
    } else {
        printf("Semaphore value after semop: %d\n", sem_val);
    }
}

// 删除信号量
if (semctl(semid, 0, IPC_RMID) == -1) {
    perror("semctl");
    exit(1);
} else {
    printf("Semaphore with id: %d removed\n", semid);
}

return 0;
}