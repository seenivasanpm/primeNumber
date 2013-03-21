#include <iostream>   // one of two
using namespace std;    // two of two, yay!
int main () 
{
	int noOfPrime =0;
	int start_s=clock();
    for (long int i=2; i<10000000; i++) 
        for (long int j=2; j<i; j++)
        {
            if (i % j == 0) 
                break;
            else if (i == j+1)
			{
				noOfPrime++;
                cout << i << " \n";
			}
        }
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	cout<<"noOfPrime = " << noOfPrime << "\n";
    return 0;
}
