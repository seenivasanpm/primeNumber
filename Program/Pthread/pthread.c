//Simple program to test threading and input.
#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 2

void *stuff();
int counter; //keeps track of the progress of the computation

int main(){
  counter=1;
  pthread_t threads[NUM_THREADS];
  pthread_create(&threads[0], NULL, stuff, NULL);

  //loop while the input is non-zero so that the program can
  //accept commands
  int input=10;
  while(input){
    input--;
    //printf("Enter 0 to exit or 1 to display progress: ");
    //scanf("%d", &input);
	printf("Currently iterating for the %dth time.\n", input);
    if(input == 2){
	
      printf("Currently iterating for the %dth time.\n", counter);
    }
  }
//  pthread_join(threads[0], NULL);
pthread_cancel(threads[0]);
return 0;
}

//Randomly chosen computation that takes a while.
void *stuff(){
  long i,j,n=100;
  for(i=0; i<=n; i++){
    for(j=0; j<=n; j++){
      //i*i*i*i*i*i*i*i*i*i*i;
      //j*j*j*j*j*j*j*j*j*j*j;
	  //wait(1000);
	  printf("i love u \n");
      //counter++;
    }
  }
  printf("...............................................................................................................Done.\n");
  pthread_exit(NULL);
}