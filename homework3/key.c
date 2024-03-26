#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>

int main()
{
    // 保存终端属性
    struct termios old_attrs, new_attrs;
    unsigned char c_in[4];
    int c;
    int ret;
    int attr = 0;



    tcgetattr(STDIN_FILENO, &old_attrs);

    // 设置终端属性
    new_attrs = old_attrs;
    new_attrs.c_cc[VTIME] = 0; // 等待的超时时间 0。1s 的整数，0表示non block
    new_attrs.c_cc[VMIN] = 0;  // 等待读到的数量，

    new_attrs.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attrs);


    // 打印提示信息
    printf("Press any key. Press 'q' to quit.\n");

    // 读取并打印按键值
    while (1) {
  //      char c = getchar();
  //      printf("Key: %c (%d) code:%02x\n", c, c,c);
  c_in[0]=0;
  c_in[1]=0;
  c_in[2]=0;
        ret = read(STDIN_FILENO, c_in, 3);
    if(ret)  printf("Key : %02x , %02x , %02x   RET:%d\n", c_in[0], c_in[1],c_in[2],ret);                                                                          
        if (c_in[0] == 'q') { // 处理退出
            break;
        }
  // printf("ret:%d\n",ret);
    }
    // 恢复终端属性
    tcsetattr(STDIN_FILENO, TCSANOW, &old_attrs);

    return 0;
}
