#include  <stdio.h>

char str[]="严hello, 1234";
int  value1=0x1234;
int  value2=-3;
char *ptr;

void main()
{
int  j, sizeofint;
sizeofint=sizeof(int);
printf("str=%s \n",str);

printf("value1 hex:%0x  dec:%d\n",value1,value1);
ptr=(char *) &value1;
printf("%p \n",str);
for(j=0;j<sizeofint;j++) {
  printf("address:%p  value:%02X\n",ptr,*ptr);
  ptr++;
  }
/*这行C语言代码是在打印一个指针`ptr`的地址和它指向的值。

`printf`是一个标准库函数，用于格式化输出到标准输出设备（通常是屏幕）。

`"address:%p  value:%02X\n"`是格式字符串，它定义了输出的格式。

- `%p`是一个格式说明符，用于打印指针的值（也就是地址）。在这里，它将打印`ptr`的值。

- `%02X`也是一个格式说明符，用于打印一个整数的十六进制表示。`02`表示宽度为2，如果整数的十六进制表示不足2位，将用0填充。`X`表示使用大写字母。在这里，它将打印`*ptr`的值，也就是`ptr`指向的字节的值。

`\n`是一个转义序列，表示换行。

所以，这行代码将打印出`ptr`的地址和它指向的字节的值。例如，如果`ptr`的值是`0x7fff5fbff8c0`，`*ptr`的值是`0x1a`，那么输出将是`address:0x7fff5fbff8c0  value:1A`。*/
printf("value2 hex:%0x  dec:%d\n",value2,value2);
ptr=(char *) &value2;
for(j=0;j<sizeofint;j++) {
  printf("address:%p  value:%02X\n",ptr,(unsigned char)*ptr);
  ptr++;
  }

}
