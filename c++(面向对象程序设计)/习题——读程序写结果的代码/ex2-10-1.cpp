#include<iostream>
using namespace std;
int print(int i){return i*i;}
double print(double d){return 2*d;}
void main(){
	int a=25;
	float b=9.2;
	double d=3.3;
	char c='a';
	short i=3;
	long l=9;
	cout<<print(a)<<endl<<print(b)<<endl<<print(d)<<endl;
	cout<<print(c)<<endl<<print(i)<<endl<<print(l)<<endl;
}
