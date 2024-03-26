#include <stdio.h>
#include <stdlib.h>

int glob1=5;
int glob2=3;

char arr[10];
extern char **environ;

int add(int a,int b)
{
 int sum;
 sum = a+b;
 printf("  sum: %p , value: %d\n",&sum,sum);
 printf("    a: %p , value: %d\n",&a,a);
 printf("    b: %p , value: %d\n\n",&b,b);
 return(sum);
}

int main(int argc, char *argv[])
{
 int sum;
 char *p;
 printf("  env: %p , value: %s\n\n",environ,*environ);
 printf(" argc: %p , value: %d\n\n",&argc,argc);
 printf("  sum: %p , value: %d\n\n",&sum,sum);
 sum=add(glob1,glob2);

 p=malloc(10);  
 *p = ' ';
 printf("    p: %p , value: %d\n\n",p,*p);
 
 printf("  arr: %p , value: %d\n",arr,arr[0]);
 printf("glob2: %p , value: %d\n",&glob2,glob2);
 printf("glob1: %p , value: %d\n\n",&glob1,glob1);
 printf(" main: %p\n",main);
 printf("  add: %p\n\n",add);
 printf("sum=%d\n\n",sum);
 return(sum);
}
/*这段代码是一个 C 程序，它展示了如何在 C 语言中使用指针和内存。这个程序包含两个函数：`add` 和 `main`。

`add` 函数接收两个整数参数 `a` 和 `b`，计算它们的和，并打印出 `a`、`b` 和 `sum` 的地址和值，然后返回 `sum`。

`main` 函数首先声明了两个变量 `sum` 和 `p`，然后打印出环境变量 `environ` 的地址和值，以及 `argc` 和 `sum` 的地址和值。然后，它调用 `add` 函数，将全局变量 `glob1` 和 `glob2` 的值相加，并将结果赋值给 `sum`。

接下来，`main` 函数使用 `malloc` 函数分配了 10 个字节的内存，并将返回的地址赋值给 `p`。然后，它将 `p` 所指向的内存的第一个字节设置为空格字符，并打印出 `p` 的地址和值。

最后，`main` 函数打印出数组 `arr`、全局变量 `glob2` 和 `glob1`、以及 `main` 和 `add` 函数的地址，然后返回 `sum`。

这个程序主要用于展示 C 语言中的内存布局和地址空间。*/