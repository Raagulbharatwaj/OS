#include <stdio.h>
#include <signal.h>
#include<stdlib.h>
void sighandler(int);
int main()
{
    signal(SIGTSTP, sighandler);
    for(;;)
    {
        
    }
    return 0;
}
void sighandler(int sig_num)
{
    printf("\nCTRL+Z is Handled\n");
    exit(1);
}