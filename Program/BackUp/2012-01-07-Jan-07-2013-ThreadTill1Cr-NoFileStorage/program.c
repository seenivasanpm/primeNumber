#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS (100)
struct primeNumber{
	long int numberVal;
	int isPrimeOrNot;
} prime[NUM_THREADS];

void *isPrime(void * primeStruct);

int main () 
{
  pthread_t threads[NUM_THREADS];
  int noOfPrime =0;
  long int start_s=clock();
  long int stop_s = 0;
  long int j = 0, i = 2;
  printf("%d \n", i);
  noOfPrime++;
  for ( i=3; i<10000000; ){
	for( j = 0,k=0; j<NUM_THREADS; j+++,k++){
		prime[j].numberVal = i+j+k;
		prime[j].isPrimeOrNot = 0;
		
		pthread_create(&threads[j], NULL, isPrime, (void *) &prime[j]);
	}
	//printf("threads created\n");
	for (j = 0; j< NUM_THREADS; j++){
		pthread_join(threads[j], NULL);
		//printf("prime number = %d localVar isPrimeOrNot= %d \n" , prime[j].numberVal, prime[j].isPrimeOrNot);
	}
	for (j = 0;j< NUM_THREADS; j++){
	//pthread_cancel(threads[j], NULL);
		if(prime[j].isPrimeOrNot){
			printf("%d \n", prime[j].numberVal);
			noOfPrime++;
		}
	}
	j++;
	i+=(NUM_THREADS*2);
  }
  stop_s=clock();  
  printf(" time %d ", (stop_s-start_s)/(1));
  printf("noOfPrime = %d",  noOfPrime);
}

void * isPrime( void * primeStruct)
{
	long int j;
	struct primeNumber* localVar;
	//printf("in thread funtion");
	localVar = (struct primeNumber *) primeStruct;
	//printf("local = %d localVar isPrimeOrNot= %d \n" , localVar->numberVal, localVar->isPrimeOrNot);
	for ( j=2; j<=localVar->numberVal; j++){
		if (localVar->numberVal % j == 0)
			break;
		else if(localVar->numberVal == 2){
			localVar->isPrimeOrNot = 1;
		//	printf("local = %d localVar isPrimeOrNot= %d \n" , localVar->numberVal, localVar->isPrimeOrNot);
		}
		else if (localVar->numberVal == j+1){
			localVar->isPrimeOrNot = 1;
			//printf("local = %d localVar isPrimeOrNot= %d \n" , localVar->numberVal, localVar->isPrimeOrNot);
		}
	 }
	  pthread_exit(NULL);
}