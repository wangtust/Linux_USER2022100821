#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"shell.h"
#include"../global/global.h"
#include"../util/str.h"
#include"../util/time.h"
#include"../function/api.h"
char * header(){
    char *buff;
    buff = (char *)malloc(sizeof(char)*100);
    sprintf(buff,"\033[33m\033[01m%s\033[0m:\033[36m\033[01m%s\033[0m$ ",sysname,pwd);
    return buff;
}
char ** getInstruction(int *argc){
    char *buff;
    char **Ins;
    buff = (char *)malloc(sizeof(char)*100);
    Ins = (char **)malloc(sizeof(char *)*10);
    for(int i=0;i<10;i++)
        Ins[i] = (char *)malloc(sizeof(char)*10);
    printf("%s",header());
    fgets(buff,100,stdin);
    buff[strlen(buff)-1]='\0';
    buff = trim(buff);
    Ins = split(buff," ",argc);
    return Ins;
}
int doOpration(int argc,char ** argv){

    if(strcmp(argv[0],"exit")==0){
        if(argc>1){
            printf("%s : too many arguments\n",argv[0]);
            return -1;
        }
        else{
            exitsys();
            return -2;
        }  
    }

    if(strcmp(argv[0],"ls")==0){
        if(argc>1){
            printf("%s : too many arguments\n",argv[0]);
            return -1;
        }
        else{
            my_ls();
            return 0;
        }  
    }

    if(strcmp(argv[0],"mkdir")==0){
        if(argc!=2){
            printf("usage %s [directory name]\n",argv[0]);
            return -1;
        }
        else{
            my_mkdir(argv[1]);
            return 0;
        }  
    }

    if(strcmp(argv[0],"cd")==0){
        if(argc!=2){
            printf("usage %s [directory name]\n",argv[0]);
            return -1;
        }
        else{
            my_cd(argv[1]);
            return 0;
        }  
    }

    if(strcmp(argv[0],"create")==0){
        if(argc!=2){
            printf("usage %s [file name]\n",argv[0]);
            return -1;
        }
        else{
            my_create(argv[1]);
            return 0;
        }  
    }

    if(strcmp(argv[0],"rm")==0){
        if(argc!=2){
            printf("usage %s [file name]\n",argv[0]);
            return -1;
        }
        else{
            my_rm(argv[1]);
            return 0;
        }  
    }

    if(strcmp(argv[0],"rmdir")==0){
        if(argc!=2){
            printf("usage %s [directory name]\n",argv[0]);
            return -1;
        }
        else{
            my_rmdir(argv[1]);
            return 0;
        }  
    }

    if(strcmp(argv[0],"open")==0){
        if(argc!=2){
            printf("usage %s [file name]\n",argv[0]);
            return -1;
        }
        else{
            my_open(argv[1]);
            return 0;
        }
    }

    if(strcmp(argv[0],"close")==0){
        if(argc!=2){
            printf("usage %s [fd num]\n",argv[0]);
            return -1;
        }
        else{
            int a;
            a = atoi(argv[1]);
            if(strcmp(argv[1],"0")&&a==0){
                printf("usage %s [fd num]\n",argv[0]);
                return -1;
            }
            my_close(a);
            return 0;
        }  
    }

    if(strcmp(argv[0],"write")==0){
        if(argc!=3){
            printf("usage %s [fd] [write method]\n",argv[0]);
            return -1;
        }
        else{
            int a1,len=0;
            char a2;
            a1 = atoi(argv[1]);
            a2 = argv[2][0];
            if((strcmp(argv[1],"0")&&a1==0)){
                printf("usage %s [fd] [write method]\n",argv[0]);
                return -1;
            }
            if(strlen(argv[1])!=1){
                printf("usage %s [fd] [write method]\n",argv[0]);
                return -1;
            }
            if(my_write(a1,&len,a2)==0){
                printf("succeed write to fd %d with %d bytes\n",a1,len);
                return 0;
            }
            return 0;
        }  
    }

    if(strcmp(argv[0],"read")==0){
        if(argc!=2){
            printf("usage %s [fd num]\n",argv[0]);
            return -1;
        }
        else{
            int a,len=0;
            a = atoi(argv[1]);
            if(strcmp(argv[1],"0")&&a==0){
                printf("usage %s [fd num]\n",argv[0]);
                return -1;
            }
            if(my_read(a,&len)==0)
                printf("read fd %d with %d bytes\n",a,len);
            return 0;
        }  
    }
    printf("%s: command not found\n",argv[0]);
    return 0;
}
void go(){
    char buff[100];
    char **argv;
    int argc,flag;
    argv = (char **)malloc(sizeof(char *)*10);
    for(int i=0;i<10;i++)
        argv[i] = (char *)malloc(sizeof(char)*10);
    while(1){
        argv = getInstruction(&argc);
        flag = doOpration(argc,argv);
        //printf("flag%d\n",flag);
        if(flag==-2)
            break;
    }
    return;
}