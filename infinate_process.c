#include<stdio.h>
#include<signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void terminate(int);
int main()
{
    signal(SIGSTOP,terminate);
    for(;;)
    {
        printf("%d\n",getpid());
        sleep(3);
    }
}
void terminate(int signum)
{
    printf("\n------------Terminate command received------------\n");
    exit(1);
}
