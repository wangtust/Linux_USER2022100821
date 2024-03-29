#include <stdio.h>

int main() {
    FILE *file = fopen("523hz8k8bit.wav", "rb");
    if (file == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

   // 跳过 WAV 文件头
    fseek(file, 44, SEEK_SET);

     // 读取前 50 个采样点的数据
    unsigned char data[50];
    fread(data, 1, 50, file);

    // 处理每个采样点的数据
    for (int y = 0; y < 27; y++) {
        for (int i = 0; i < 50; i++) {
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

    fclose(file);
    return 0;
}