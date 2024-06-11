#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate = 0.05, interest, total;
    int years;

    printf("请输入存入的美元数: ");
    scanf("%lf", &principal);

    printf("请输入年数: ");
    scanf("%d", &years);

    total = principal * pow((1 + rate), years);
    interest = total - principal;

    printf("在 %d 年后，你将获得 %.2lf 美元的利息，总金额将变为 %.2lf 美元。\n", years, interest, total);

    return 0;
}