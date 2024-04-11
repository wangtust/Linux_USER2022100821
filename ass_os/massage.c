#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>  
#include <sys/wait.h>
// 定义消息结构体
struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key;
    int msgid;
    struct msgbuf msg;

    // 创建键
    key = ftok("progfile", 65);

    // 创建消息队列
    msgid = msgget(key, 0666 | IPC_CREAT);
    msg.mtype = 1;

    pid_t pid = fork();
    if (pid == 0) {  // 子进程1
        printf("Enter data to be written to message queue : ");
        fgets(msg.mtext, 100, stdin);

        // 向消息队列发送数据
        msgsnd(msgid, &msg, sizeof(msg), 0);

        printf("Data sent to message queue: %s\n", msg.mtext);
    } else {  // 父进程
        wait(NULL);  // 等待子进程结束

        // 从消息队列接收数据
        msgrcv(msgid, &msg, sizeof(msg), 1, 0);

        printf("Data received from message queue: %s\n", msg.mtext);

        // 销毁消息队列
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}