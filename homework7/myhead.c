#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    int opt;
    int num_lines = 10; // 默认打印10行

    // 解析命令行选项
    while ((opt = getopt(argc, argv, "n:")) != -1) {
        if (opt == 'n') {
            num_lines = atoi(optarg); // 将字符串转换为整数
        } else {
            printf("用法: %s [-n <行数>] [<文件名>]\n", argv[0]);
            return 1;
        }
    }

    FILE *file;

    // 检查是否提供了文件名参数
    if (optind == argc) {
        file = stdin; // 从标准输入读取
    } else if (optind == argc - 1) {
        if (strcmp(argv[optind], "-") == 0) {
            file = stdin; // 从标准输入读取
        } else {
            file = fopen(argv[optind], "r"); // 打开文件
            if (file == NULL) {
                printf("错误: 文件 '%s' 未找到\n", argv[optind]);
                return 1;
            }
        }
    } else {
        printf("用法: %s [-n <行数>] [<文件名>]\n", argv[0]);
        return 1;
    }

    char line[MAX_LINE_LENGTH]; // 读取文件中的每一行
    for (int i = 0; i < num_lines; i++) {
        if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
            break; // 文件结束或出错
        }
        printf("%s", line);
    }

    if (file != stdin) {
        fclose(file); // 关闭文件
    }

    return 0;
}