#include<iostream.h>
double f(int a=10,int b=20,int c=5){return a*b*c;}
int main(){
	cout<<f()<<endl<<f(20)<<endl<<f(10,10)<<endl<<f(10,10,10)<<endl;
}
