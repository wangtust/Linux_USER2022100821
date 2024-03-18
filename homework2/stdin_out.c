#include <stdio.h>

int main() {
    int ch;

    // 从标准输入读取字符，直到遇到文件结尾
    while ((ch = getchar()) != EOF) {
        // 将读取的字符写入到标准输出
        putchar(ch);
    }

    return 0;
}
