# include "test1.h"
Atm::Atm(string name,string password,double money)
{
	(*this).name=name;
	cout<<"����name"<<endl;
	(*this).password=password;
	cout<<"����password"<<endl;
	(*this).money=money;
	cout<<"����money"<<endl;
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