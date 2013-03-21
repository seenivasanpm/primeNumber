#include <fcntl.h> 
#include<stdio.h>
#include<unistd.h>
char string[] = "Hi"; 
main (int argc, char *argv)
{
	int writeNum = 0; int readNum= 0,fd,i=0; ;
	pid_t childpid = 1, pid = 0, ppid=0;
	char buf[256];
	memset(buf, 0x00, sizeof(char)*256);
	mkfifo ("mypipe", 0666); //create pipe
	childpid = fork();
	if (childpid != 0) {
		fd = open("fifo", O_WRONLY); 
		char buffer1[256];
		for(i = 0; i<1000; i++){			
			sprintf(buffer1, "%s %3d", string, i);
			write(fd, buffer1, 6); //write buf into pipe
			printf("write = %s\n", buffer1);
		}
	}else{
		fd = open("fifo", O_RDONLY); 
		for(i = 0; i<1000; i++){
			read(fd, buf, 6); //read buf from pipe
			printf("READ  = %s\n", buf);
		}
	}
}