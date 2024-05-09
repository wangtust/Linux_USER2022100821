// 引入消息队列相关的头文件
#include <mqueue.h>
// 引入输入输出相关的头文件
#include <stdio.h>
// 引入一些常用函数的头文件，如exit
#include <stdlib.h>

int main() {
    // mqd_t是消息队列描述符的类型
    mqd_t mq;
    // mq_attr是消息队列属性的结构体
    struct mq_attr attr;

    // 初始化消息队列属性
    attr.mq_flags = 0;      // 队列标志，0表示默认属性，非阻塞
    attr.mq_maxmsg = 10;    // 队列中最大消息数
    attr.mq_msgsize = 1024; // 每个消息的最大长度
    attr.mq_curmsgs = 0;    // 队列中当前的消息数，这个属性不能被设置，只能被获取

    // 创建或打开一个消息队列
    // "/test_queue"是消息队列的名字
    // O_CREAT | O_RDWR表示如果消息队列不存在则创建，且可读写
    // 0644是消息队列的权限，表示拥有者可读写，同组用户和其他用户可读
    // &attr是消息队列的属性
    mq = mq_open("/test_queue", O_CREAT | O_RDWR, 0644, &attr);
    // 如果mq_open返回-1，表示出错
    if (mq == (mqd_t) -1) {
        // 打印错误信息
        perror("mq_open");
        // 退出程序
        exit(1);
    }

    // 打印消息队列创建成功的信息
    printf("Message queue created\n");
    // 关闭消息队列
    mq_close(mq);

    return 0;
}