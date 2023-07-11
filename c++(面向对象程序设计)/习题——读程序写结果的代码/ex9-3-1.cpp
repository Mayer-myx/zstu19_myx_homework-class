#include<iostream>
#include<fstream>
using namespace std;
void main(){
	fstream ou,in;
	ou.open("a.dat",ios::out);
	ou<<"on fact\n";
	ou<<"operating file \n";
	ou<<"is the same as inputing/outputing data on screen...\n";
	ou.close();
	char buffer[80];
	in.open("a.dat",ios::in);
	while(!in.eof())
	{
		in.getline(buffer,80);
		cout<<buffer<<endl;
	}
}
