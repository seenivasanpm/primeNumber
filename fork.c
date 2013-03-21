#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
main()
{
	pid_t pid, ppid;
	pid_t childpid = 1;
	int status;
	pid = getpid();
	ppid= getppid();	
	printf("pid = %d, ppid = %d childpid =%d\n", pid, ppid, childpid);
	childpid = fork();
	pid = getpid();
	ppid= getppid();	
	printf("pid = %d, ppid = %d childpid =%d\n", pid, ppid, childpid);
	//if(childpid == 0)
		sleep(1);
	//else
	if(childpid != 0)
		waitpid(childpid,&status,0);
	pid = getpid();
	ppid= getppid();
	printf("pid = %d, ppid = %d childpid =%d\n", pid, ppid, childpid);
}