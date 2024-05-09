#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct sockaddr* SP;

int main(int argc,const char* argv[])
{
    // 创建socket
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(0 > sockfd)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // 准备地址
    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3031);
    addr.sin_addr.s_addr = INADDR_ANY;
    socklen_t addrlen = sizeof(addr);

    // 绑定
    if(bind(sockfd,(SP)&addr,addrlen))
    {
        perror("bind");
        return EXIT_FAILURE;
    }

    // 监听
    if(listen(sockfd,5))
    {
        perror("listen");
        return EXIT_FAILURE;
    }

    // 等待连接
    int clifd = accept(sockfd,(SP)&addr,&addrlen);
    if(0 > clifd)
    {
        perror("accept");
        return EXIT_FAILURE;
    }

    char buf[4096] = {};
    size_t buf_size = sizeof(buf);

    for(;;)
    {
        // 接收/返回数据
        memset(buf,0,sizeof(buf));
        size_t ret_size = read(clifd,buf,sizeof(buf));
        if(0 == strcmp("quit",buf))
        {
            printf("通信结束!\n");
            break;
        }   
        if(0 == ret_size)
        {
            printf("连接断开!\n");
            break;
        }
        printf("recv:[%s] bytes:%d\n",buf,(int)ret_size);
        strcat(buf,":return");
        write(clifd,buf,strlen(buf)+1);
    }

    // 关闭socket
    close(clifd);
}
