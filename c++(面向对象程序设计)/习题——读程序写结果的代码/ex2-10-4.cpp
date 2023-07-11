#include<iostream>
using std::endl;
using std::cout;
int &f(int& a,int b=20)
{
	 a=a*b;
	 return a;
}
int main(){
	int j=10;
	int &m=f(j);
	int *p=&m;
	cout<<j<<endl;
	m=20;
	cout<<j<<endl;
	f(j,5);
	cout<<j<<endl;
	*p=300;
	cout<<j<<endl;
}