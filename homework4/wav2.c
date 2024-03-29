#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define DATA_LEN 50

int main() {
    FILE *file = fopen("523hz8k8bit.wav", "rb");
    if (file == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

    // 跳过 WAV 文件头
    fseek(file, 44, SEEK_SET);

    // 读取前 50 个采样点的数据
    unsigned char data[DATA_LEN];
    fread(data, 1, DATA_LEN, file);

    while (!feof(file)) {
        printf("\x1b[H\x1b[2J"); // 清屏

        // 处理每个采样点的数据
        for (int y = 0; y < 27; y++) {
            for (int i = 0; i < DATA_LEN; i++) {
                // 将采样点的值除以 10
                int value = data[i] / 10;

                // 显示图形
                if (y == (26 - value)) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // 向左移动一个单位
        memmove(data, data + 1, (DATA_LEN - 1) * sizeof(unsigned char));
        fread(data + DATA_LEN - 1, 1, 1, file);

        usleep(100000l);  //延时100ms
    }

    fclose(file);
    return 0;
}