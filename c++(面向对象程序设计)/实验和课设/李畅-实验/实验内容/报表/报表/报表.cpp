#include"iostream"
#include"cstdlib"
#include"string"
#include"list"
using namespace std;
class People{
protected:
	string name;
	string sex;
	int age;
	int ID;
	double pay;
public:
	People(string name=0,string sex=0,int age=0,int ID=0,double pay=0){
		this->name=name;
		this->sex=sex;
		this->age=age;
		this->ID=ID;
		this->pay=pay;
		this->pay=getpay();
	}
	string getName(){return name;}
	string getSex(){return sex;}
	int getAge(){return age;}
	int getID(){return ID;}
	virtual double getpay(){return 0;}
	virtual void print(){}
};
class Boss:public People{
public:
	Boss(string name,string sex,int age,int ID,double pay):People(name,sex,age,ID,pay){
		this->name=name;
		this->sex=sex;
		this->age=age;
		this->ID=ID;
		this->pay=pay;
		this->pay=getpay();
	}
	double getpay(){return pay/12;}
	void print(){
		cout<<"BOSS:    "<<"\t"<<name<<"\t"<<sex<<"\t"<<age<<"\t"<<ID<<"\t"<<pay<<endl;
	}
};
class Employee:public People{
	double reward;
public:
	Employee(string name,string sex,int age,int ID,double pay,double reward):People(name,sex,age,ID,pay){
		this->name=name;
		this->sex=sex;
		this->age=age;
		this->ID=ID;
		this->pay=pay;
		this->reward=reward;
		this->pay=getpay();
	}
	double getpay(){return pay+reward;}
	void print(){
		cout<<"Employee:"<<"\t"<<name<<"\t"<<sex<<"\t"<<age<<"\t"<<ID<<"\t"<<pay<<endl;
	}
};
class HourlyWorker:public People{
	double dayhour;
	int day;
public:
	HourlyWorker(string name,string sex,int age,int ID,double pay,double dayhour,int day):People(name,sex,age,ID,pay){
		this->name=name;
		this->sex=sex;
		this->age=age;
		this->ID=ID;
		this->pay=pay;
		this->dayhour=dayhour;
		this->day=day;
		this->pay=getpay();
	}
	double getpay(){return pay*dayhour*day;}
	void print(){
		cout<<"HourlyWorker:"<<"\t"<<name<<"\t"<<sex<<"\t"<<age<<"\t"<<ID<<"\t"<<pay<<endl;
	}
};
class Marketers:public People{
	double profit;
public:
	Marketers(string name,string sex,int age,int ID,double pay,double profit):People(name,sex,age,ID,pay){
		this->name=name;
		this->sex=sex;
		this->age=age;
		this->ID=ID;
		this->pay=pay;
		this->profit=profit;
		this->pay=getpay();
	}
	double getpay(){return pay+profit*0.05;}
	void print(){
		cout<<"Marketers:"<<"\t"<<name<<"\t"<<sex<<"\t"<<age<<"\t"<<ID<<"\t"<<pay<<endl;
	}
};
class Report{
public:
	void add(list<People *> &people,People *p){
		people.push_back(p);
	}
	void print(list<People *> people){
		list<People *>::iterator point;
		for(point=people.begin();point!=people.end();point++){
			(*point)->print();
		}
	}
};
void main()
{
	list<People *> people;
	People (*a)=new Boss("刘大海","男",40,1001,150000);
	People (*b)=new Employee("黄春秀","女",30,1501,2000,500);
	People (*c)=new HourlyWorker("王小虎","男",25,2001,15,8,20);
	People (*d)=new Marketers("李小龙","男",28,2501,2000,5000);	Report re;
	re.add(people,a);
	re.add(people,b);
	re.add(people,c);
	re.add(people,d);
	cout<<"*******************************************************************************"<<endl;
	cout<<"TYPE        "<<"    NAME "<<"\t"<<"SEX"<<"\t"<<"AGE"<<"\t"<<"ID"<<"\t"<<"SALARY"<<endl;
	cout<<"*******************************************************************************"<<endl;
	re.print(people);
	system("pause");
} 