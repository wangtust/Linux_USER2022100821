#include <stdio.h>
#include <unistd.h>
#include <string.h>
//严


int main() {
    char *data = "Hello World !\n";
    printf("pid=%d, main address:%p,  data address:%p data:%s\n", getpid(), main, data);

    FILE *file = fopen("hello1.txt", "w"); // 打开文件，以写入方式打开
    if (file == NULL) { // 检查文件是否成功打开
        perror("Error opening file");
        return 1;
    }

    // 将内容写入文件
    fprintf(file, "pid=%d, main address:%p,  data address:%p data:%s\n", getpid(), main, data, data);

    fclose(file); // 关闭文件

    return 0;
}
