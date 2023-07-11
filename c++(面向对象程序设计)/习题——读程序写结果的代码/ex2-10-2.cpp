#include<iostream>
using namespace std;
int n;                               	
int *p1;  
void  fun()
{
	static int a;                       
	int b;                            	
	cout<<"a="<<a<<", ";
	cout<<"b="<<b<<endl;
}                        	
void main(){
	int *p2;                          
	int m;                            
	fun();          
	{
		int n(10),m(20);	
		cout<<"n="<<n<<endl<<"m="<<m<<endl;   
	}
	cout<<"n="<<n<<endl<<"m="<<m<<endl;   
	if(p1)cout<<"p1="<<p1<<endl;        
	if(p2)cout<<"p2="<<p2<<endl;        
}
