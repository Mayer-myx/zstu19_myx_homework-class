#include<iostream>
using namespace std;
class A{
	int x;
public:
	A():x(0){cout<<"constructor A() called..."<<endl;}
	A(int i):x(i){cout<<"X"<<x<<"\tconstructor..."<<endl;}
	~A(){cout<<"X"<<x<<"\tdestructor..."<<endl; }
};
class B{
	int y;
	A X1;
	A X2[3];
public:
	B(int j):X1(j),y(j){cout<<"B"<<j<<"\tconstructor..."<<endl;}
	~B(){cout<<"B"<<y<<"\tdestructor..."<<endl; }
};
void main(){
	A X1(1),X2(2);
	B B1(3);
}
