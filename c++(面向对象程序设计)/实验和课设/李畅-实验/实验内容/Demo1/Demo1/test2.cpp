# include"test1.h"
void main(){
	Atm atm1("Bob","123456",2300);
	Atm atm2("Marry","000000",4000);
	cout<<"name����Ŀռ��СΪ:"<<sizeof(atm1.name)<<endl;
	cout<<"password����Ŀռ��СΪ:"<<sizeof(atm1.password)<<endl;
	cout<<"money����Ŀռ��СΪ:"<<sizeof(atm1.money)<<endl;
	cout<<"atm�������Ŀռ��СΪ:"<<sizeof(atm1)<<endl;

	cout<<"atm1�е�name����ĵ�ַΪ:"<<&atm1.name<<endl;
	cout<<"atm1�е�password����ĵ�ַΪ:"<<&atm1.password<<endl;
	cout<<"atm1�е�money����ĵ�ַΪ:"<<&atm1.money<<endl;
	cout<<"atm1�е�money����ĵ�ַΪ:"<<endl;
	cout<<"����getMoney() �ĵ�ַΪ��"<<endl;
	printf("%lx\n",&Atm::getMoney);
	cout<<"atm2�е�name����ĵ�ַΪ:"<<&atm2.name<<endl;
	cout<<"atm2�е�password����ĵ�ַΪ:"<<&atm2.password<<endl;
	cout<<"atm2�е�money����ĵ�ַΪ:"<<&atm2.money<<endl;
	cout<<"atm2�������ĵ�ַΪ:"<<&atm2<<endl;
	system("pause");
}