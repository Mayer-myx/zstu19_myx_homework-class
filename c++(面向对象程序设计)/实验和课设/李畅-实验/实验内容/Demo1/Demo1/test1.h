# include <iostream>
# include <string>
# include <cstdlib>
using namespace std;
class Atm
{
public:
	string name;
	string password;
	double money;
public:
	Atm(string name,string password,double money);
	void setName(string name);
	string getName();
	void setPassword(string password);
	string getPassword();
	void setMoney(double money);
	double getMoney();
};