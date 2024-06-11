#include <stdio.h>
#include <string.h>

#define DISK_SIZE 1000  // 定义虚拟磁盘的大小
#define MAX_FILES 100   // 定义最大文件数量

// 定义文件结构体
typedef struct {
    char name[100];  // 文件名
    int start;       // 文件在虚拟磁盘上的起始位置
    int length;      // 文件长度
} File;

File files[MAX_FILES];  // 文件数组，用于存储文件信息
char disk[DISK_SIZE];   // 虚拟磁盘，用于存储文件数据
int num_files = 0;      // 当前文件数量

// 格式化操作，清空虚拟磁盘和文件数组
void format() {
    memset(disk, 0, DISK_SIZE);
    num_files = 0;
}

// 创建文件操作
// name: 文件名
// length: 文件长度
// 返回值：0表示成功，-1表示失败
int create(char* name, int length) {
    // 检查是否超过最大文件数量
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files\n");
        return -1;
    }

    // 寻找足够的空间来存储文件
    int start = 0;
    for (int i = 0; i < num_files; i++) {
        if (files[i].start >= start + length) {
            break;
        }
        start = files[i].start + files[i].length;
    }

    // 检查是否有足够的空间来存储文件
    if (start + length > DISK_SIZE) {
        printf("Error: Not enough space\n");
        return -1;
    }

    // 在文件数组中添加新的文件
    strcpy(files[num_files].name, name);
    files[num_files].start = start;
    files[num_files].length = length;
    num_files++;

    return 0;
}

// 删除文件操作
// name: 文件名
// 返回值：0表示成功，-1表示失败
int delete(char* name) {
    // 在文件数组中找到指定的文件
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            // 删除文件，并将后面的文件向前移动
            for (int j = i; j < num_files - 1; j++) {
                files[j] = files[j + 1];
            }
            num_files--;
            return 0;
        }
    }

    // 如果找不到指定的文件，返回错误
    printf("Error: File not found\n");
    return -1;
}

// 主函数，用于测试上述操作
int main() {
    format();               // 格式化虚拟磁盘
    create("file1", 100);   // 创建一个名为"file1"，长度为100的文件
    create("file2", 200);   // 创建一个名为"file2"，长度为200的文件
    delete("file1");        // 删除名为"file1"的文件
    return 0;
}