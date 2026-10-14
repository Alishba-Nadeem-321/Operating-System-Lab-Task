#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
   cout<<"parent process -> PID: "<<GetCurrentProcessId()<<" | Child PID: 1234 (Simulated)"<<endl;
   	cout<<"Child process -> PID: 1234 "<<GetCurrentProcessId()<<"(Simulated)"<<endl;
   	return 0;
}