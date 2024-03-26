#include <stdio.h>

int main() {
    FILE *file = fopen("fdata.txt", "rb");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    char str[12];
    int intVal1;
    int intVal2;
    float floatVal1;
    float floatVal2;
    float floatVal3;
    float floatVal4;

    fread(str, sizeof(char), 12, file);//注意要用sizeof函数，只写%s，%d会出错
    fread(&intVal1, sizeof(int), 1, file);
    fread(&intVal2, sizeof(int), 1, file);
    fread(&floatVal1, sizeof(float), 1, file);
    fread(&floatVal2, sizeof(float), 1, file);
    fread(&floatVal3, sizeof(float), 1, file);
    fread(&floatVal4, sizeof(float), 1, file);

    printf("String: %s\n", str);
    printf("Integer1: %x\n", intVal1);
    printf("Integer2: %d\n", intVal2);
    printf("Float1: %f\n", floatVal1);
    printf("Float2: %f\n", floatVal2);
    printf("Float3: %f\n", floatVal3);
    printf("Float4: %f\n", floatVal4);

    fclose(file);
    return 0;
}