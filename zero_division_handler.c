#include <stdio.h>
#include <signal.h>
#include<stdlib.h>
void sighandler(int);
int main()
{
    signal(SIGFPE,sighandler);
    int y = 20/0;
    return 0;
}
void sighandler(int sig_num)
{
    printf("Division by zero handled\n");
    exit(1);
}