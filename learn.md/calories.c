#include <stdio.h>

double calculate_calories(double weight, double height, double age, int convert_to_kj) {
    double calories = 66 + 13.7 * weight + 5.0 * height - 6.8 * age;
    if (convert_to_kj) {
        // 1千卡 = 4.18千焦
        return calories * 4.18;
    } else {
        return calories;
    }
}

int main() {
    double weight, height, age, daily_calorie_gap;
    int convert_to_kj;
FILE *file = fopen("food_calories.txt", "r");
    if (file == NULL) {
        printf("无法打开文件\n");
        return 1;
    }

    char food[100];
    double kcal;
    while (fgets(food, sizeof(food), file) != NULL) {
        char *p = food;
        while (*p != '\0' && *p != '\n') {
            p++;
        }
        *p = '\0';

        if (sscanf(p - 4, "%lf", &kcal) == 1) {
            double kj = kcal * 4.18;
            printf("食物：%s，千卡：%f，千焦：%f\n", food, kcal, kj);
        }
    }

    fclose(file);
    printf("请输入你的体重（kg）：");
    scanf("%lf", &weight);

    printf("请输入你的身高（cm）：");
    scanf("%lf", &height);

    printf("请输入你的年龄（岁）：");
    scanf("%lf", &age);

    printf("你希望将结果转换为千焦吗？（输入1表示是，0表示否）：");
    scanf("%d", &convert_to_kj);

    double energy = calculate_calories(weight, height, age, convert_to_kj);
    if (convert_to_kj) {
        printf("你一天的基础消耗能量是：%.2f 千焦\n", energy);
    } else {
        printf("你一天的基础消耗能量是：%.2f 千卡\n", energy);
    }

    printf("请输入你每天的热量缺口（千卡或千焦）：");
    scanf("%lf", &daily_calorie_gap);

    double total_energy_to_lose_1kg_fat = convert_to_kj ? 32231 : 7700;
    double days_to_lose_1kg_fat = total_energy_to_lose_1kg_fat / daily_calorie_gap;

    printf("你需要 %.2f 天才能消耗1kg脂肪\n", days_to_lose_1kg_fat);

    return 0;
}