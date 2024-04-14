#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World! Welcome to C-programming.";
    char *token = strtok(str, " ,.-!");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ,.-!");
    }
printf("str=");
    for (int i = 0; i < sizeof(str); i++) {
        if (str[i] == '\0') {
            printf("\\0");
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
 // str=Hello\0 World!\0Welcome\0to\0C\0programming\0\0
 //可以看到str中的空格和逗号还有-被替换成了\0
    return 0;
}