#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
main()
{
	pid_t pid, ppid, childpid[10];
	int i = 0,msqid,ndash,status;;
	//childpid[0]= fork();
	//printf("pid= %d, ppid= %d, childpid = %d, i = %d \n",getpid(), getppid(),childpid[i], i);
	for(i=0;i<4;i++){
			if(0 == (childpid[i] = fork()))
			//printf("pid= %d, ppid= %d, childpid = %d, i = %d \n",getpid(), getppid(),childpid[i], i);
			//if(childpid[i] == 0)
				break;
				//;
		}
	/*if(childpid[0]){
		printf("wait pid= %d, ppid= %d, childpid = %d, i = %d \n",getpid(), getppid(),childpid[i], i);
		//waitpid(childpid[0],&status,0);//	sleep(100);
	}
	else{
	//	sleep(1);		
	}*/
	sleep(10);
	//waitpid(childpid[0],
	printf("exit pid= %d, ppid= %d, childpid = %d, i = %d \n",getpid(), getppid(),childpid[i], i);
}