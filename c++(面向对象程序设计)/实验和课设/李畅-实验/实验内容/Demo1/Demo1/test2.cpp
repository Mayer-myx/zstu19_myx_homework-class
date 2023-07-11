# include"test1.h"
void main(){
	Atm atm1("Bob","123456",2300);
	Atm atm2("Marry","000000",4000);
	cout<<"name分配的空间大小为:"<<sizeof(atm1.name)<<endl;
	cout<<"password分配的空间大小为:"<<sizeof(atm1.password)<<endl;
	cout<<"money分配的空间大小为:"<<sizeof(atm1.money)<<endl;
	cout<<"atm对象分配的空间大小为:"<<sizeof(atm1)<<endl;

	cout<<"atm1中的name分配的地址为:"<<&atm1.name<<endl;
	cout<<"atm1中的password分配的地址为:"<<&atm1.password<<endl;
	cout<<"atm1中的money分配的地址为:"<<&atm1.money<<endl;
	cout<<"atm1中的money分配的地址为:"<<endl;
	cout<<"函数getMoney() 的地址为："<<endl;
	printf("%lx\n",&Atm::getMoney);
	cout<<"atm2中的name分配的地址为:"<<&atm2.name<<endl;
	cout<<"atm2中的password分配的地址为:"<<&atm2.password<<endl;
	cout<<"atm2中的money分配的地址为:"<<&atm2.money<<endl;
	cout<<"atm2对象分配的地址为:"<<&atm2<<endl;
	system("pause");
}