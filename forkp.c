#include<stdio.h>
int main(){
	int i,childpid;
	childpid= fork();
	int status;
	if(!childpid)
	{
	for(i=0;i<5;i++){
		printf("\n childpid = %d pid= %d, ppid = %d", childpid, getpid(), getppid());
		sleep(1);
		}
	}
	//else
		//waitpid(childpid,&status,0);
}