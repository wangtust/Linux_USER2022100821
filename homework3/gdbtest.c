#include <stdio.h>

int add(int start, int end) {
    int i, sum = 0;
    for(i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int result;
    result = add(1, 10);
    printf("result=%d\n", result);

    return 0;
}