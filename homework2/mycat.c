#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

// 显示文件内容（文本方式）
void displayText(FILE *file) {
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }
}

// 显示文件内容（十六进制方式）
void displayHex(FILE *file) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%02X ", ch); // 打印十六进制数
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // 确保命令行参数的正确性
    if (argc != 2 && !(argc == 3 && strcmp(argv[1], "-h") == 0)) {
        printf("Usage: %s [-h] filename\n", argv[0]);
        return 1;
    }

    char *filename = argv[argc - 1]; // 获取文件名
    FILE *file = fopen(filename, "r"); // 以只读方式打开文件
    if (file == NULL) { // 检查文件是否成功打开
        perror("Error opening file");
        return 1;
    }

    if (argc == 3 && strcmp(argv[1], "-h") == 0) { // 检查是否需要以十六进制方式显示文件内容
        displayHex(file); // 显示文件内容（十六进制方式）
    } else {
        displayText(file); // 显示文件内容（文本方式）
    }

    fclose(file); // 关闭文件
    return 0;
}
