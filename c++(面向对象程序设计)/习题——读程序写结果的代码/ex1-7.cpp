#include<iostream>
#include<string>
using namespace std;
struct teacher{
	char name[20];
	char work[20];
	int count;
	int pay;
}num;
int main()
{   while(cin>>num.name>>num.work>>num.count)
	{
		if(strcmp(num.work,"教授")==0)
				num.pay=100*num.count;
		if(strcmp(num.work,"副教授")==0)
				num.pay=80*num.count;
		if(strcmp(num.work,"讲师")==0)
				num.pay=60*num.count;
		if(strcmp(num.work,"助教")==0)
				num.pay=40*num.count;
		cout<<num.name<<' '<<num.pay<<endl;		
	}
	return 0;	
}
