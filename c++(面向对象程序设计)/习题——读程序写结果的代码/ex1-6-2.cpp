#include<iostream.h>
#include<iomanip.h>   
void main()
{
	int a=20,b=18,c=24;
	cout<<"123456789012345678901234567890"<<"\n";
	cout<<setiosflags(ios::left);
	cout<<hex<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
	cout<<oct<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
	cout<<resetiosflags(ios::left);
	cout<<dec<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
}
/*
123456789012345678901234567890
14		  12		18
24        22        30
        20        18        24
*/