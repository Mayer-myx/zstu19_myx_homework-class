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
		if(strcmp(num.work,"����")==0)
				num.pay=100*num.count;
		if(strcmp(num.work,"������")==0)
				num.pay=80*num.count;
		if(strcmp(num.work,"��ʦ")==0)
				num.pay=60*num.count;
		if(strcmp(num.work,"����")==0)
				num.pay=40*num.count;
		cout<<num.name<<' '<<num.pay<<endl;		
	}
	return 0;	
}
