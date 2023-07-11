# include"calculator.h"
calculator::calculator(double a,double b,char c)
{
	(*this).a=a;
	(*this).b=b;
	(*this).c=c;
}

void calculator:: add(calculator cal)
{
    double sum=0;
    sum=cal.a+cal.b;
    cout<<"结果为："<<sum<<endl;
}
void calculator:: subduction (calculator cal)
{
	double sum=0;
	sum=cal.a-cal.b;
	cout<<"结果为："<<sum<<endl;
}
void calculator:: multiplicative(calculator cal)
{
	double sum=0;
	sum=cal.a*cal.b;
	cout<<"结果为："<<sum<<endl;
}
void calculator:: division(calculator cal)
{ 
	if(cal.b==0)
	{
		cout<<"除数不能为零."<<endl;
	}
	else
	{
	double sum=0;
	sum=cal.a/cal.b;
	cout<<"结果为："<<sum<<endl;
	}
}
void calculator:: residue(calculator cal)
{
	if(cal.b==0)
	{
		cout<<"除数不能为零."<<endl;
	}
	else
	{
	int sum=0;
	sum=(int)cal.a%(int)cal.b;
	cout<<"结果为："<<sum<<endl;
	}
}