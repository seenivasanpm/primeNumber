#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int globalVariable = 2;
int main()
{
	int    iStackVariable = 20;
	int i = 0;
	pid_t pID;
	printf("first log\n");
	pID	= vfork();
	
	if (pID == 0)                // child
	{
		globalVariable++;
		iStackVariable++;
		printf("child process globalVariable =%d, iStackVariable = %d\n",globalVariable, iStackVariable );
		
	}
	else if (pID < 0)            // failed to fork
	{
		return 1;
	}
	else                                   // parent
	{
		globalVariable+=5;
		iStackVariable+=5;
		printf("parent process globalVariable =%d, iStackVariable = %d\n",globalVariable, iStackVariable );
	}
	//_exit(1);
	return 0;
}
