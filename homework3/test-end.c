#include  <stdio.h>

char str[]="hello, 1234";
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

printf("value2 hex:%0x  dec:%d\n",value2,value2);
ptr=(char *) &value2;
for(j=0;j<sizeofint;j++) {
  printf("address:%p  value:%02X\n",ptr,(unsigned char)*ptr);
  ptr++;
  }

}
