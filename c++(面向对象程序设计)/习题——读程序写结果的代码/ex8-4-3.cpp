#include<iostream>
using namespace std;
class excep{
private:
	char *ch;
public:
	excep(char *m="exception class..."){ch=m;}
	void print(){cerr<<ch<<endl;}
};
void err1(){
	cout<<"enter err1\n";
	throw excep("exception");
}
void err2(){
	try{cout<<"enter err2\n";	err1();	}
	catch(int){cerr<<"err2:catch\n";	throw;	}
}
void err3(){
	try{	cout<<"enter err3\n";	err2();	}
	catch(...){cerr<<"err3:chtch\n";	throw;	}
}
void main(){
	try{		err3();	}
	catch(...)	{	cerr<<"main:catch\n";	}
}
