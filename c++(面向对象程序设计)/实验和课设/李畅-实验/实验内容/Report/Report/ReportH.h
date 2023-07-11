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
	double pay;      //�ܹ���(��һ�¼���)
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
	double yearSalary;       //Boss��н
public:
	Boss(string name,int id,int age,string sex,double yearSalary);
	void setYearSalary(double yearSalary);
    double getYearSalary();
	double getPay();
	void print();
};
class Employee:public Person{
private:
	double baseSalary;      //Employeeһ���µĻ�������
	double award;   //Employeeһ���µĽ���
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
	double workHour;    // HourlyWorkerһ���¹�����Сʱ
	double hourSalary;  // HourlyWorkerһ��Сʱ�Ĺ���
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
	double baseSalary;    //CommWorkerһ���µĻ�������
	double profit;       //CommWorkerһ���µ���������
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