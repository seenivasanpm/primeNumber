#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
main()
{
	pid_t pid;
	int status,i=1;
	printf("\nInside main function %d\n",i);
	printf("\nCalling fork function%d\n",i);
	if(pid=fork()<0){
		printf("Child did not get created %d\n",i);
	}else{
		i=2;
		printf("Hurray am created %d\n",i);
	}
	printf("\nCalled fork function %d\n",i);
	printf("\nEnd of main function %d\n",i);
	pid = wait(&status);  //try without giving this line
}
