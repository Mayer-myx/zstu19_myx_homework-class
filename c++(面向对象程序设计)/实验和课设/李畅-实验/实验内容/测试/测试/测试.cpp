#include"iostream" 
#include"math.h"  
using namespace std;  
class Calculator{  
private: 
public: 
	int choice;
    double count;
	Calculator(){}; 
    Calculator(double a):count(a){};  
    double getcount(){  
        return count;  
    }  
    Calculator& operator++(); 
    Calculator& operator++(int);
    Calculator& operator--();
    Calculator& operator--(int); 
    Calculator& operator+(Calculator b);
    Calculator& operator-(Calculator b); 
};   
Calculator& Calculator::operator++(){  
    ++count;  
	cout<<"ǰ�������Ϊ��"<<count<<endl ;
	return *this;
} 
Calculator& Calculator::operator++(int){  
	count=count++; 
	cout<<"���������Ϊ:"<<count<<endl;
	return *this;
} 
Calculator& Calculator::operator--(){  
    count=--count;  
	cout<<"ǰ�Լ����Ϊ:"<<count<<endl;
	return *this;
}  
Calculator& Calculator::operator--(int){  
    count=count--;  
   	cout<<"���Լ����Ϊ:"<<count<<endl;
	return *this;
}
Calculator& Calculator::operator+(Calculator b){
	cout<<"������ڶ����������Ľ��"<<endl;
	cin>>b.count;
	count=count+b.count;
    cout<<"����������������Ϊ��"<<count<<endl ;  
	return *this;
}  
Calculator& Calculator::operator-(Calculator b){
	cout<<"������ڶ����������Ľ��"<<endl;
	cin>>b.count;
	count=count-b.count;
    cout<<"����������������Ϊ��"<<count<<endl ;
	return *this;
}  
void main()  
{  
    Calculator a,b;
	cout<<"�������������ʾ�Ľ��"<<endl;
    cin>>a.count;
	if (a.count>65535||a.count<0) {
		cout<<"���㳬�����÷�Χ,����0-65535����������"<<endl;
		cin>>a.count;
	}
	cout<<"***************************"<<endl;
	cout<<"������Ҫ���е����㣺"<<endl;
    cout<<"1��ǰ����"<<endl;
    cout<<"2��������"<<endl;
	cout<<"3��ǰ�Լ�"<<endl;
	cout<<"4�����Լ�"<<endl;
	cout<<"5������������������"<<endl;
	cout<<"6������������������"<<endl;
    cout<<"***************************"<<endl;
    cin>>a.choice;
    while(1){
    	switch(a.choice){
    	case 1:a.operator++();
			break;
		case 2:a.operator++(1);
		    break;
	    case 3:a.operator--();
		    break;
	    case 4:a.operator--(1);
		    break;
	    case 5:a.operator+(b);
		    break;
	    case 6:a.operator-(b);
		    break;
 	    }
	cout<<"***************************"<<endl;
	cout<<"������Ҫ���е����㣺"<<endl;
    cout<<"1��ǰ����"<<endl;
    cout<<"2��������"<<endl;
	cout<<"3��ǰ�Լ�"<<endl;
	cout<<"4�����Լ�"<<endl;
	cout<<"5������������������"<<endl;
	cout<<"6������������������"<<endl;
    cout<<"***************************"<<endl;
    cin>>a.choice;
	}
	 system("pause");
}  
