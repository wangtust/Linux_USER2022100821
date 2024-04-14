#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 256

int main(void) {
char * myargv[]={"uid","-l",NULL};

char    buf[MAXLINE];
pid_t   fpid;
int             status;
printf("%d%% ",getpid());       /* print prompt (printf requires %% to print %) */
while (fgets(buf, MAXLINE, stdin) != NULL) {
  buf[strlen(buf) - 1] = 0;     /* replace newline with null */
  if ( (fpid = fork()) < 0) return (-1) ;  // fork error
  else if (fpid == 0) {         /* child */
  execvp(buf,myargv) ;
    printf("fpid=%d,ppid=%d,pid=%d,couldn't execute: %s\n",
                    fpid,getppid(),getpid(),buf);
    exit(-1);
  }
  else if (fpid >0)
  {     /* parent */
    if ( (waitpid(fpid, &status, 0)) < 0) return(-1); // wait error
    printf("fpid=%d,ppid=%d,pid=%d%% ",fpid,getppid(),getpid());
  }
 }
return(0);
}
