#include"iostream"
#include"cstdlib"
#include"math.h"
using namespace std;
class Triangle{
private:
    double a;
    double b;
    double c;
	double p;
	double area;
public:
	Triangle(){};
	Triangle(double l1,double l2,double l3){
        a=l1;
        b=l2;
		c=l3;
		p=(a+b+c)/2;
		area=sqrt(p*(p-a)*(p-b)*(p-c));
    }
    double getarea(){return area;}
    friend Triangle operator+(Triangle m,Triangle n);
	friend ostream &operator<<(ostream &os,Triangle t);
 };
Triangle operator+(Triangle m,Triangle n){
	Triangle t;
	t.area=m.area+n.area;
	return t;
}
ostream &operator<<(ostream &os,Triangle t){
	os<<"the area of triangle(triangles) is "<<t.getarea()<<endl;
	return os;
}
void main()
{
	Triangle t1(3,5,7),t2(4,4,6),t3(5,5,8);
	cout<<t1<<endl;
	cout<<t2<<endl;
	cout<<t3<<endl;
	cout<<t1+t2<<endl;
	cout<<t1+t2+t3<<endl;
	system("pause");
}