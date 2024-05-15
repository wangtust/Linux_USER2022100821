#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define ARG_MAX_COUNT 10
#define ARG_MAX_LENGTH 20

int main() {
    char command[100];
    char *args[ARG_MAX_COUNT + 1];
    char *output_file = NULL;
    char *input_file = NULL;  // 新增
    int count, i, j, pid, fd;

    while (1) {
        // 输出提示符并读取命令
        printf("%% ");
        if(fgets(command, sizeof(command) / sizeof(char), stdin)==NULL) return 0;

        // 去除末尾的换行符
        command[strlen(command) - 1] = '\0';

        // 处理命令行参数
        count = 0;
        args[count++] = strtok(command, " \t");
        while ((args[count] = strtok(NULL, " \t")) != NULL) {
            count++;
        }
        args[count] = NULL;

        // 处理输入输出重定向
        for (i = 0; i < count; i++) {
            if (strcmp(args[i], ">") == 0) {
                output_file = args[i + 1];
                args[i] = NULL;
            } else if (strcmp(args[i], "<") == 0) {  // 新增
                input_file = args[i + 1];
                args[i] = NULL;
            }
        }

        if (strcmp(args[0],"cd") == 0)  // 如果是内部命令，不需要fork 子进程
        {
            if (args[1] == NULL) {
                fprintf(stderr, "Expected argument to \"cd\"\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("cd");
                }
            }
        }
        else   // 外部命令， 需要 fork 子进程去运行
        {
            // 创建子进程并执行命令
            pid = fork();
            if (pid == -1) {
                perror("fork");
                return 1;
            } else if (pid == 0) {
                // 子进程
                if (output_file != NULL) {
                    fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                    if (fd != -1) {
                        dup2(fd, STDOUT_FILENO);
                        close(fd);
                    } else {
                        perror("output_file");
                        return 1;
                    }
                }

                if (input_file != NULL) {  // 新增
                    fd = open(input_file, O_RDONLY);
                    if (fd != -1) {
                        dup2(fd, STDIN_FILENO);
                        close(fd);
                    } else {
                        perror("input_file");
                        return 1;
                    }
                }

                execvp(args[0], args);
                perror("execvp");
                return 1;
            } else {
                // 父进程
                wait(NULL);
            }
        }

        // 重置变量
        output_file = NULL;
        input_file = NULL;  // 新增
    }

    return 0;
}