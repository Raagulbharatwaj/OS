#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int child = fork();
    if(child>0)
    {
        printf("PARENT:\n");
        printf("PROCESS ID: %d\n",getpid());
        printf("PROCESS ID OF PARENT: %d\n",getppid());
    }
    else
    {
        printf("CHILD:\n");
        printf("PROCESS ID: %d\n",getpid());
        printf("PROCESS ID OF PARENT: %d\n",getppid());
    }
}