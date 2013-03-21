#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	pid_t pid;
  	pid = fork();

	//child process
  	if(pid == 0){
	        //do something
  	}	

        //parent process
  	else{
        	//do something
	}
  return 0;
}