#include<iostream.h>
class Shape{
public:
	virtual double area(){return 0;}
virtual void print()=0; 
};
class Circle:public Shape{
protected:
	double r;
public:
	Circle(double x):r(x){}
	double area(){ return 3.14*r*r; }
    void print(){cout<<"Circle : r="<<r<<"\t area="<<area()<<endl; }
};
class Cylinder:public Circle{
	double h;
public:
	Cylinder(double r,double x):Circle(r),h(x){}
	double area(){return 2*3.14*r*r+2*3.14*h;}	
};
void shapeArea(Shape &s){	cout<<s.area()<<endl;}
void shapePrint(Shape *p){	p->print();}
void main(){
	Shape *s[3];
	s[0]=&Circle(10);
	s[1]=&Cylinder(20,100);
	for(int i=0;i<2;i++){
		shapeArea(*s[i]);
		shapePrint(s[i]);
	}
}
