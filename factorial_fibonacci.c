#include<stdio.h>
#include<unistd.h>
int fibo(int);
long fact(int);
int main()
{
    
    printf("PARENT:\n");
    printf("PROCESS ID: %d\n",getpid());
    printf("FIBONACCI NUMBER OF 20: %d\n",fibo(20));
    int child = fork();
    if(child==0)
    {
        printf("CHILD:\n");
        printf("PROCESS ID: %d\n",getpid());
        printf("FACTORIAL OF 10: %ld\n",fact(10));
    }
}
int fibo(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return (fibo(n-1)+fibo(n-2));
    }
}
long fact(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}