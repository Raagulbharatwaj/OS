#include<stdio.h>
#include<signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void terminate_parent(int);

int main()
{
    signal(SIGQUIT, terminate_parent);
    int child = fork();
    if (child == 0)
    {
        int a = 100;
        int c = 0;
        for(int i=1;i<=a;i++)
        {
            if(a%i==0)
            {
                c++;
            }
        }
        printf("No of diviors of %d is %d\n",a,c);
        kill(getppid(),SIGQUIT);
    }
    else
    {
        sleep(3);
    }
    return 0;
}
void terminate_parent(int signum)
{
    printf("Terminate signal received from child\n");
    exit(1);
}