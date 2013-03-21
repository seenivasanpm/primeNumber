#include <iostream>   // one of two
#include <stdio.h>
#include <string.h>
//#include <pthread>

using namespace std;    // two of two, yay!

//seenivasan just to check
#define NUM_THREADS (100)
//#define PRIME_MAX_LIMIT 10000000
  #define PRIME_MAX_LIMIT 100000
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
  //printf("%d \n", i);
  cout<< "2 \n3 \n5 \n 7\n11 \n13" << endl;
  noOfPrime = 6;//++;
  for ( i=15; i<PRIME_MAX_LIMIT; ){
  int numberOfThreads = 0;
	memset(threads, 0x00, sizeof(pthread_t) *NUM_THREADS);
	for( j = 0, numberOfThreads = 0; numberOfThreads<NUM_THREADS; j++){
	prime[j].numberVal = i+(j*2);
		prime[j].isPrimeOrNot = 0;
		//cout<< "prime = "<<  prime[j].numberVal;
		/*if( PRIME_MAX_LIMIT <= prime[j].numberVal)
		{
			cout<< "PRIME MAX reached\n";
			break;
		}*/
		if(!(
			(!(prime[j].numberVal % 3 )) || \
			(!(prime[j].numberVal % 5)) || \
			(!(prime[j].numberVal % 7 )) || \
			(!(prime[j].numberVal % 11 )) || \
			(!(prime[j].numberVal % 13 ))
		)){
			//cout<< "seeni create pthread\n";
			numberOfThreads++;
			pthread_create(&threads[numberOfThreads], NULL, isPrime, (void *) &prime[j]);
		}
	}
	i= i+(j*2);
	//printf("threads created\n");
	for (j = 0; j< NUM_THREADS; j++){
	//cout<< "seeni join pthread\n";
		//if(threads[j])
			pthread_join(threads[j], NULL);
		//printf("prime number = %d localVar isPrimeOrNot= %d \n" , prime[j].numberVal, prime[j].isPrimeOrNot);
	}
	for (j = 0;j< NUM_THREADS; j++){
	//cout<< "seeni isPrime pthread\n";
		//pthread_cancel(threads[j], NULL);
		if(prime[j].isPrimeOrNot){
//		cout<< "seeni Prime pthread\n";
			//store prime number
			//storePrimeNumber();
			//printf("%d \n", prime[j].numberVal);
			cout<< prime[j].numberVal<< endl;
			noOfPrime++;
		}
	}
	//j++;
	//i+=(NUM_THREADS*2);
	}  
	stop_s=clock();  
	//printf(" time %d ", (stop_s-start_s)/(1));
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	//printf("noOfPrime = %d",  noOfPrime);
	cout<< "noOfPrime =" << noOfPrime;
}

void * isPrime( void * primeStruct)
{
	long int j;
	struct primeNumber* localVar;
	//printf("in thread funtion");
	localVar = (struct primeNumber *) primeStruct;
	//printf("local = %d localVar isPrimeOrNot= %d \n" , localVar->numberVal, localVar->isPrimeOrNot);
	//cout<< "seeni" << localVar->numberVal<<endl;
	for ( j=15; j<=localVar->numberVal; j+=2){
		if (localVar->numberVal % j == 0)
		{
		//cout<< "divide by"<< j<<endl;
			break;
			}
/*		else if(localVar->numberVal == 2){
		
			localVar->isPrimeOrNot = 1;
			//printf("local = %d localVar isPrimeOrNot= %d \n" , localVar->numberVal, localVar->isPrimeOrNot);
		}*/
		else if((localVar->numberVal) < (j*7)){
			localVar->isPrimeOrNot = 1;
			break;
		}
		/*else if (localVar->numberVal == j+2){
		//cout<< "it is prime"<<endl;
			localVar->isPrimeOrNot = 1;
			//printf("local = %d localVar isPrimeOrNot= %d \n" , localVar->numberVal, localVar->isPrimeOrNot);
		}*/
	}
	pthread_exit(NULL);
}


//this is also just to check