#include <stdio.h>

int main()
{
    int i, data;
    while(1)
    {
        int sum = 0;  // 将sum的初始化放在循环内部，每次循环开始时都会被重置为0

        printf("please input a num(<100)\n");
        scanf("%d", &data);

        for(i=1; i<=data; i++)
            sum += i;

        printf("sum from 1 to %d is: %d\n", data, sum);
    }

    return 0;
}