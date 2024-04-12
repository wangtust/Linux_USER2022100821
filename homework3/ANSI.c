#include <stdio.h>

int main() {
    // 清除屏幕
    printf("\033[2J");

    // 将光标移动到(10, 20)位置
    printf("\033[10;20H");

    // 设置文本颜色为红色
    printf("\033[31m");

    // 打印一条消息
    printf("Hello, world!");

    // 重置文本颜色
    printf("\033[0m");

    return 0;
}