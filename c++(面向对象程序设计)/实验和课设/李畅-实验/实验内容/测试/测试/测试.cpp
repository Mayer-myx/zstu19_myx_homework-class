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
	cout<<"前自增结果为："<<count<<endl ;
	return *this;
} 
Calculator& Calculator::operator++(int){  
	count=count++; 
	cout<<"后自增结果为:"<<count<<endl;
	return *this;
} 
Calculator& Calculator::operator--(){  
    count=--count;  
	cout<<"前自减结果为:"<<count<<endl;
	return *this;
}  
Calculator& Calculator::operator--(int){  
    count=count--;  
   	cout<<"后自减结果为:"<<count<<endl;
	return *this;
}
Calculator& Calculator::operator+(Calculator b){
	cout<<"请输入第二个计算器的结果"<<endl;
	cin>>b.count;
	count=count+b.count;
    cout<<"两个计算器结果相加为："<<count<<endl ;  
	return *this;
}  
Calculator& Calculator::operator-(Calculator b){
	cout<<"请输入第二个计算器的结果"<<endl;
	cin>>b.count;
	count=count-b.count;
    cout<<"两个计算器结果相减为："<<count<<endl ;
	return *this;
}  
void main()  
{  
    Calculator a,b;
	cout<<"请输入计算器显示的结果"<<endl;
    cin>>a.count;
	if (a.count>65535||a.count<0) {
		cout<<"计算超出可用范围,请在0-65535内重新输入"<<endl;
		cin>>a.count;
	}
	cout<<"***************************"<<endl;
	cout<<"请输入要进行的运算："<<endl;
    cout<<"1、前自增"<<endl;
    cout<<"2、后自增"<<endl;
	cout<<"3、前自减"<<endl;
	cout<<"4、后自减"<<endl;
	cout<<"5、两个计算器结果相加"<<endl;
	cout<<"6、两个计算器结果相减"<<endl;
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
	cout<<"请输入要进行的运算："<<endl;
    cout<<"1、前自增"<<endl;
    cout<<"2、后自增"<<endl;
	cout<<"3、前自减"<<endl;
	cout<<"4、后自减"<<endl;
	cout<<"5、两个计算器结果相加"<<endl;
	cout<<"6、两个计算器结果相减"<<endl;
    cout<<"***************************"<<endl;
    cin>>a.choice;
	}
	 system("pause");
}  
