#include<stdio.h>
#include<stdlib.h>
#include<sys/syscall.h>
#include<time.h>
void main() 
{ 
    clock_t begins = clock(); 
    int cp=0; 
    FILE *fp; 
    char ch; 
    int wrd=0; 
    fp = fopen("t1.txt","r"); 
    while ((ch = fgetc(fp)) != EOF) 
    { 
        if(ch==' '||ch=='\n') 
        { 
            wrd++; 
        } 
    } 
    fclose(fp); 
    printf("word count in file = %d",wrd); 
    clock_t ends =clock(); 
    float timep = (float)(ends - begins)/ CLOCKS_PER_SEC; 
    printf("\n Execution time taken for procedural call=%f\n", timep); 
    begins = clock(); 
    system("wc -w t1.txt"); 
    ends = clock(); 
    float times = (float)(ends- begins) / CLOCKS_PER_SEC; 
    printf("\n Execution time taken for system call=%f\n", times); 
    printf("Time difference = %f\n", times-timep); 
}
