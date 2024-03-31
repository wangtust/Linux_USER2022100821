#include <stdio.h>

char dot_A[9] = {0x00, 0x08, 0x14, 0x22, 0x41, 0x41, 0x7f, 0x41, 0x41};

void disp_char(char dispc, char dot[9]) {
    int i, j;
    // 遍历点阵的每一行
    for (i = 0; i < 9; i++) {
        // 遍历点阵的每一列
        for (j = 0; j < 7; j++) {
            // 使用位运算检查点阵的每一位，如果位为1，则打印输入的字符
            if ((dot[i] >> j) & 0x01) 
                printf("%c", dispc);
            else 
                // 否则打印空格
                printf(" ");
        }
        // 每打印完一行后换行
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s char\n", argv[0]);
        return 0;
    }

    char replace_char = argv[1][0];
    disp_char(replace_char, dot_A);

    return 0;
}