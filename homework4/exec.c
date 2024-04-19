#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

char * myenv[]={"KEY1=key1","TEST=Value",NULL};
char * myargv[]={"uid","-l",NULL};

extern char ** environ;

void main(int argc, char *argv[])
{
if (argc<2)
{
printf("Usage: ./exec arg \n");
return;
}

printf("in %s : \n ", argv[0]);
printf("enviro[0]: %s : \n ", environ[0]);
printf("uid=%d, euid=%d, pid=%d, ppid=%d\n",
        getuid(),geteuid(),getpid(),getppid());

printf("before exec %s: \n ",argv[1]);

if (execve(argv[1],myargv,myenv) == -1)
 perror("execve");

printf("after exec: \n ");

}
