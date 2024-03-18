#include <stdio.h>

char dot_A[][8]={
    "0000000",
    "0001000",
    "0010100",
    "0100010",
    "1000001",
    "1000001",
    "1111111",
    "1000001",
    "1000001"
};

char dot_0[][8]={
    "0111100",
    "1000010",
    "1000010",
    "1000010",
    "1000010",
    "1000010",
    "1000010",
    "1000010",
    "0111100"
};
char dot_1[][8]={
     "0001000",
     "0011000",
     "0101000",
     "0001000",
     "0001000",
     "0001000",
     "0001000",
     "0001000",
     "0111111"
};
char dot_2[][8]= {
        "0111110",
        "1000001",
        "0000001",
        "0000010",
        "0000100",
        "0001000",
        "0010000",
        "0100000",
        "1111111"
    };
char dot_3[][8]={
        "1111111",
        "0000001",
        "0000010",
        "0000100",
        "0001000",
        "0111100",
        "0000010",
        "0000010",
        "1111100"
    };
char dot_4[][8]={
        "0001000",
        "0011000",
        "0101000",
        "1001000",
        "1111111",
        "0001000",
        "0001000",
        "0001000",
        "0001000"
    };
char dot_5[][8]= {
        "1111111",
        "1000000",
        "1000000",
        "1111100",
        "0000010",
        "0000010",
        "0000010",
        "1111100",
        "0000000"
    };
char dot_6[][8]={
        "0111110",
        "1000001",
        "1000000",
        "1111100",
        "1000010",
        "1000001",
        "1000001",
        "0111110",
        "0000000"
    };
char dot_7[][8]={
        "1111111",
        "0000001",
        "0000010",
        "0000100",
        "0001000",
        "0010000",
        "0100000",
        "1000000",
        "0000000"
    };
char dot_8[][8]={
        "0111110",
        "1000001",
        "1000001",
        "1000001",
        "0111110",
        "1000001",
        "1000001",
        "1000001",
        "0111110"
    };
char dot_9[][8]= {
        "0111110",
        "1000001",
        "1000001",
        "1000001",
        "0111111",
        "0000001",
        "0000010",
        "0111100",
        "0000000"
    };//创建数组存他那个点阵，下面再构建的打印函数
void disp_char(char dispc, char dot[][8]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 7; j++) {
            if (dot[i][j] == '1') 
                printf("%c", dispc);
            else 
                printf(" ");
        }
        printf("\n");
    }
}//构建个打印函数，传递两个变量，打印的字符和遍历数组

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s char1 char2\n", argv[0]);
        return 0;
    }

    char character = argv[1][0];
    char replace_char = argv[2][0];//传递给main函数的两个参数

    if (character == 'A') 
        disp_char(replace_char, dot_A);
    else if (character == '0') 
        disp_char(replace_char, dot_0);
    else if (character == '1') 
        disp_char(replace_char, dot_1);
    else if (character == '2') 
        disp_char(replace_char, dot_2);
    else if (character == '3') 
        disp_char(replace_char, dot_3);
    else if (character == '4') 
        disp_char(replace_char, dot_4);
    else if (character == '5') 
        disp_char(replace_char, dot_5);
    else if (character == '6') 
        disp_char(replace_char, dot_6);
    else if (character == '7') 
        disp_char(replace_char, dot_7);
    else if (character == '8') 
        disp_char(replace_char, dot_8);
    else if (character == '9') 
        disp_char(replace_char, dot_9);
    else 
        printf("Character not supported\n");

    return 0;
}
