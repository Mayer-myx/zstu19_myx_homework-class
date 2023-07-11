#include<iostream>
using namespace std;
class A{
public:
	void virtual f(){cout<<"f() in class A"<<endl;}
};
class B:public A{
public:
	void f(){cout<<"f() in class B"<<endl;}
	void fb(){cout<<"normal function fb \n";}
};
class C:public A{
public:
	void f(){cout<<"f() in class C"<<endl;}
	void fc(){cout<<"normal function fc"<<endl;}
};
void f(A *p){
	p->f();
	if (typeid(*p)==typeid(B)) {
		B *bp=dynamic_cast<B*>(p);
		bp->fb();
	}
	if (typeid(*p)==typeid(C)){
		C *bc=dynamic_cast<C*>(p);
		bc->fc();
	}
}
void main(){
	A *pa;	B b; 	C c;
	pa=&b;	f(pa);
	pa=&c;	f(pa);
}
