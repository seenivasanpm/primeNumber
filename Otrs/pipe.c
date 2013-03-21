#include <fcntl.h> 
#include<stdio.h>
#include<unistd.h>
char string[] = "child hw it is managing....."; 
main (int argc, char *argv)
{
	int writeNum = 0; int readNum= 0;
	int fd,i=0; 
	char buf[256];
	memset(buf, 0x00, sizeof(char)*256); 
	/* create named pipe with read/write permission for all users */ 
	printf("\nInside main function\n");
	mknod("fifo", S_IFIFO | 0666, 0); 
	
	if (argc == 2) 
	{
	printf("argc 2\n");
		fd = open("fifo", O_WRONLY); 
		}
	else 
	{
	printf("argc 1\n");
		fd = open("fifo", O_RDONLY); 
		}
	for (i=0;i<10000;i++){
	printf("for\n");
		if (argc == 2){
		char buf2[256];
		memset(buf2, 0x00, sizeof(char)*256); 
		sprintf(buf2, "%s%4d", string, i);
			printf("write = %s\n", buf2);
			
			//sleep(1);
			write(fd, buf2, 32); 
		}else{
			
			read(fd, buf, 32); 
			//if(!readNum)
				//sleep(1);
			//printf("READ = %d\n", readNum++);
			printf("READ = %s\n", buf);
		}
	}
}