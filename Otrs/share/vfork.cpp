#include <iostream>
#include <string>
// Required by for routine
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int globalVariable = 2;
main()
{
	string sIdentifier;
	int    iStackVariable = 20;
	pid_t pID = vfork();
	if (pID == 0)                // child
	{
		// Code only executed by child process
		sIdentifier = "Child Process: ";
		globalVariable++;
		iStackVariable++;
		cout << sIdentifier;
		cout << " Global variable: " << globalVariable;
		cout << " Stack variable: "  << iStackVariable << endl;
		//sleep(20000);
		_exit(0);
	}
	else if (pID < 0)            // failed to fork
	{
		cerr << "Failed to fork" << endl;
		_exit(1);   // Throw exception
	}
	else                                   // parent
	{
		// Code only executed by parent process
		sIdentifier = "Parent Process:";
		globalVariable+=5;
		iStackVariable+=5;
	}
	// executed only by parent
	cout << sIdentifier;
	cout << " Global variable: " << globalVariable;
	cout << " Stack variable: "  << iStackVariable << endl;
	_exit(2);
}
