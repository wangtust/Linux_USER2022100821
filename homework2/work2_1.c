#include<stdio.h>
int main(){
    printf("ASCII码十进制，十六进制，字符\n");
    for(int i=0;i<128;i++)
    printf("%d              %x       %c \n",i,i,i);
    return 0;
}