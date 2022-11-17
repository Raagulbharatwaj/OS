// CPP code to create three child
// process of a parent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int pid, pid1, pid2;
    printf("PARENT CREATED MY PROCESS ID IS %d\n",getpid());
	pid = fork();
    if(pid == 0) 
    {
		printf("CHILD-1 CREATED FROM PARENT %d MY PROCESS ID IS %d\n",getppid(),getpid());
        sleep(3);
		printf("CHILD-1 WITH PROCESS ID %d TERMINATED\n",getpid());
	}
	else 
    {
		pid1 = fork();
		if (pid1 == 0) 
        {
			printf("CHILD-2 CREATED FROM PARENT %d MY PROCESS ID IS %d\n",getppid(),getpid());
            sleep(2);
			printf("CHILD-2 WITH PROCESS ID %d TERMINATED\n",getpid());
		}
		else 
        {
			pid2 = fork();
			if (pid2 == 0) 
            {
				printf("CHILD-3 CREATED FROM PARENT %d MY PROCESS ID IS %d\n",getppid(),getpid());
                printf("CHILD-3 WITH PROCESS ID %d TERMINATED\n",getpid());
			}
			else 
            {
				sleep(4);
				printf("PARENT WITH PROCESS ID %d TERMINATED\n",getpid());
			}
		}
	}
	return 0;
}
