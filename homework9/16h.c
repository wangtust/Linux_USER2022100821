#include <stdio.h>

int main() {
    unsigned long int num1, num2, product;

    printf("请输入第一个16进制数: ");
    scanf("%lx", &num1);

    printf("请输入第二个16进制数: ");
    scanf("%lx", &num2);

    product = num1 * num2;

    printf("乘积为: %lx\n", product);

    return 0;
}