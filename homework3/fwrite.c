#include  <stdio.h>

// 定义一些全局变量
char str[]="严hello, 1234";  // 字符串
int  value1 = 0x1234;  // 整数
int  value2 = -3;  // 整数
float value3 =-10.5;  // 浮点数
float value4 = 16.625;  // 浮点数
float f1 = 123.234567;  // 浮点数
float f2 = 123.234568;  // 浮点数

int main()
{
    int  j, sizeofint;
    FILE *fp;

    // 以二进制方式打开文件，如果打开失败，则打印错误信息并返回-1
    if( (fp=fopen("fdata.txt", "wb+")) == NULL ){  
        puts("Fail to open file!");
        return(-1);
    }

    sizeofint = sizeof(int);
    // 将各个变量的值写入到文件中
    fwrite(str, 12, 1, fp);  // 写入字符串
    fwrite(&value1, sizeof(int), 1, fp);  // 写入整数
    fwrite(&value2, sizeof(int), 1, fp);  // 写入整数
    fwrite(&value3, sizeof(float), 1, fp);  // 写入浮点数
    fwrite(&value4, sizeof(float), 1, fp);  // 写入浮点数
    fwrite(&f1, sizeof(float), 1, fp);  // 写入浮点数
    fwrite(&f2, sizeof(float), 1, fp);  // 写入浮点数
    
    // 在控制台上打印各个变量的值
    printf("str:%s \n", str);
    printf("value1:%d \n", value1);
    printf("value2:%d \n", value2);
    printf("value3:%f \n", value3);
    printf("value4:%f \n", value4);
    printf("f1:%f \n", f1);
    printf("f2:%f \n", f2);
   
    // 关闭文件
    fclose(fp);
    return(0);
}