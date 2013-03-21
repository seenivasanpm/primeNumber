#include<stdio.h>
#include<stdlib.h>

main()
{
   long   int i, num = 1, numofprime = 0;
   char ch;
   FILE *fp;
 
   printf("Enter the number of prime numbers required\n");
//   scanf("%d",&n);
 
   while(num<=1000000){
	i=2; while(i<=num){
	   if(num%i==0)
		break;
	   i++;
	}
   if(i==num){
	numofprime++;
	printf("%ld is Prime\n",num);
   }
   num++;
   } 
   printf("numofprime = %ld \n",numofprime);
   return 0;
}
