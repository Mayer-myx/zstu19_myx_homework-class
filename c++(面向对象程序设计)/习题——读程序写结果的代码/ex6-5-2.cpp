#include<iostream.h>
#include<string.h>
class X{
private:
	char *s;
public:
	X(char *b){
		s=new char[sizeof(b)+1];
		strcpy(s,b);
	}
	~X(){delete s;}
	void display(){	cout<<"s="<<s<<endl;	}
};
void main(){
	X x1("ok");
	X x2(x1);
	X x3=x1;
	x2.display();
	x3.display();
}
