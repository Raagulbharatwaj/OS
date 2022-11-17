#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct warehouse
{
    int lock;
    int capacity;
}warehouse;

void manufacture(warehouse*);
void distribute(warehouse*);

int main()
{
    warehouse* w = (warehouse*)malloc(sizeof(warehouse));

    w->lock = 0;
    w->capacity = 20;
    
    int child1,child2;

    child1 = fork();
    if(child1==0)
    {
        for(;;)
            manufacture(w);
    }
    else
    {
        sleep(1);
        child2 = fork();
        if(child2==0)
        {
            for(;;)
                distribute(w);
        }
    }
}
void manufacture(warehouse* w)
{
    if(w->lock)
    {
        sleep(2);
    }
    else
    {
        w->lock = 1;
        w->capacity--;
        printf("Producer Produced 1 unit\n");
        printf("Capacity: %d\n",w->capacity);
        w->lock = 0;
        sleep(2);
    }
}
void distribute(warehouse* w)
{
    if(w->lock)
    {
        sleep(2);
    }
    else
    {
        w->lock = 1;
        w->capacity++;
        printf("Distributer Sold 1 unit\n");
        printf("Capacity: %d\n",w->capacity);
        w->lock = 0;
        sleep(2);
    }
}
