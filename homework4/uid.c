#include <stdio.h>
#include <unistd.h>

extern char ** environ;

void main(int argc, char ** argv)
{

char cc;
printf("in argv[0]%s : \n ", argv[0]);
printf("in argv[1]%s : \n ", argv[1]);
printf("enviro[0]: %s : \n ", environ[0]);
printf("enviro[1]: %s : \n ", environ[1]);
printf("uid=%d, euid=%d, pid=%d, ppid=%d\n",
        getuid(),geteuid(),getpid(),getppid());
printf(" end of uid \n ");
}
