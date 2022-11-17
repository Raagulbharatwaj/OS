#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct database
{
    int write_lock;
    int data;
}database;

void read(database);
void write(database);

int main()
{
    database* d = (database*)malloc(sizeof(database));
    d->write_lock = 1;
    d->data = 20;
}

void write(database* d,int n)
{
    if(d->write_lock==0)
    {
        sleep(2);
    }
    else
    {
        d->write_lock = 1;
        d->data = n;
        d->write_lock = 0;
    }
}
void read(database* d)
{
    if(d->write_lock==0)
    {
        sleep(2);
    }
    else
    {
        printf("Data:%d\n",d->data);
    }
}