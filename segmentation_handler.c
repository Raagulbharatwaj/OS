#include <stdio.h>
#include <signal.h>
#include<stdlib.h>
void sighandler(int);
int main()
{
    signal(SIGSEGV,sighandler);
    int* x = 0;
    int y = *x;
    return 0;
}
void sighandler(int sig_num)
{
    printf("Segmentation fault handled\n");
    exit(1);
}