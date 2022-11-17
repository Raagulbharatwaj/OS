#include<stdio.h>
#include<signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid;
    printf("enter the pid to terminate");
    scanf("%d",&pid);
    kill(pid,SIGSTOP);
}