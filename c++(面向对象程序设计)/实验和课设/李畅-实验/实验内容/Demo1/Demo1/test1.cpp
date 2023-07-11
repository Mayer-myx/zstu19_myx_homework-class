# include "test1.h"
Atm::Atm(string name,string password,double money)
{
	(*this).name=name;
	cout<<"创建name"<<endl;
	(*this).password=password;
	cout<<"创建password"<<endl;
	(*this).money=money;
	cout<<"创建money"<<endl;
}
void Atm::setName(string name)
{
	(*this).name=name;
}

string Atm::getName()
{
	return name;
}

void Atm::setPassword(string password)
{
	(*this).password=password;
}

string Atm::getPassword()
{
	return password;
}

void Atm::setMoney(double money)
{
	(*this).money=money;
}

double Atm::getMoney()
{
	return money;
}