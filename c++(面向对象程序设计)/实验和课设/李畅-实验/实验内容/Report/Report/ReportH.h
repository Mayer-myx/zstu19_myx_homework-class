# include <iostream>
# include <string>
# include <list>
using namespace std;
class Person{
protected:
	string name;
	int id;
	int age;
	string sex;
	double pay;      //总工资(按一月计算)
public:
	Person(string name,int id,int age,string sex);
	void setName(string name);
	string getName();
	void setId(int id);
	int getId();
	void setAge(int age);
	int getAge();
	void setSex(string sex);
	string getSex();
	void setPay(double pay);
	virtual double getPay();
	virtual void print();
};
class Boss:public Person{
private:
	double yearSalary;       //Boss年薪
public:
	Boss(string name,int id,int age,string sex,double yearSalary);
	void setYearSalary(double yearSalary);
    double getYearSalary();
	double getPay();
	void print();
};
class Employee:public Person{
private:
	double baseSalary;      //Employee一个月的基本工资
	double award;   //Employee一个月的奖金
public:
	Employee(string name,int id,int age,string sex,double baseSalary,double award);
	void setBaseSalary(double baseSalary);
    double getBaseSalary();
	void setAward(double award);
    double getAward();
	double getPay();
	void print();
};
class HourlyWorker:public Person{
private:
	double workHour;    // HourlyWorker一个月工作的小时
	double hourSalary;  // HourlyWorker一个小时的工资
public:
	HourlyWorker(string name,int id,int age,string sex,double workHour,double hourSalary);
	void setWorkHour(double workHour);
    double getWorkHour();
	void setHourSalary(double hourSalary);
    double getHourSalary();
	double getPay();
	void print();
};
class CommWorker:public Person{
private:
	double baseSalary;    //CommWorker一个月的基本工资
	double profit;       //CommWorker一个月的销售利润
public:
	CommWorker(string name,int id,int age,string sex,double baseSalary,double profit);
	void setBaseSalary(double baseSalary);
    double getBaseSalary();
	void setProfit(double profit);
    double getProfit();
	double getPay();
	void print();
};
class Report{
public:
	void add(list<Person *> &persons,Person *p);
	void print(list<Person *> persons);
};