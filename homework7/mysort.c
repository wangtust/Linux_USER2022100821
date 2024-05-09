#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INITIAL_LINES 10

// 用于 qsort 的比较函数
int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    FILE *file;
    if (argc == 1) {
        file = stdin; // 从标准输入读取
    } else if (argc == 2) {
        file = fopen(argv[1], "r"); // 打开文件
        if (file == NULL) {
            printf("错误: 文件 '%s' 未找到\n", argv[1]);
            return 1;
        }
    } else {
        printf("用法: %s [<文件名>]\n", argv[0]);
        return 1;
    }

    size_t lines_allocated = INITIAL_LINES;
    char **lines = malloc(lines_allocated * sizeof(char *));
    size_t num_lines = 0;

    // 读取所有的行
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (num_lines == lines_allocated) {
            lines_allocated *= 2;
            lines = realloc(lines, lines_allocated * sizeof(char *));
        }
        lines[num_lines] = strdup(line);
        num_lines++;
    }

    if (file != stdin) {
        fclose(file); // 关闭文件
    }

    // 对行进行排序
    qsort(lines, num_lines, sizeof(char *), compare);

    // 打印排序后的行
    for (size_t i = 0; i < num_lines; i++) {
        printf("%s", lines[i]);
        free(lines[i]);
    }

    free(lines);

    return 0;
}