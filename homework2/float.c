#include <stdio.h>

typedef union {
    float f;
    unsigned int i;
} FloatUnion;

void print_binary(unsigned int value) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    FloatUnion u;

    // 正数
    u.f = 1.0f;
    printf("二进制表示 of %f: ", u.f);
    print_binary(u.i);

    // 负数
    u.f = -1.0f;
    printf("二进制表示 of %f: ", u.f);
    print_binary(u.i);

    // 零
    u.f = 0.0f;
    printf("二进制表示 of %f: ", u.f);
    print_binary(u.i);

    return 0;
}
/*这段代码是在打印浮点数在内存中的二进制表示。这是通过使用C语言的联合（union）和位操作实现的。

联合（union）是一种特殊的数据结构，它允许在相同的内存位置存储不同的数据类型。在这个例子中，我们定义了一个联合，它可以存储一个浮点数（`f`）或一个无符号整数（`i`）。

当我们将一个浮点数存储在联合中，然后通过访问联合的整数部分，我们可以查看浮点数在内存中的二进制表示。

这段代码中的浮点数遵循IEEE 754标准，这是一种用于浮点数算术的技术标准，它定义了浮点数的表示方法、舍入规则、异常处理等。

在IEEE 754标准中，一个单精度（32位）浮点数由三部分组成：

1. 符号位（1位）：决定了数的正负，0表示正数，1表示负数。
2. 指数位（8位）：表示数的规模大小。
3. 尾数位（23位）：表示数的精度。

这段代码中的`print_binary`函数就是将这个32位的二进制表示打印出来。*/