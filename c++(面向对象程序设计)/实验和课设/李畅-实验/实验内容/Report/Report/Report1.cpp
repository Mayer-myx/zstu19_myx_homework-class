# include "ReportH.h"
Person::Person(string name,int id,int age,string sex){
	(*this).name = name;
	(*this).id = id;
	(*this).age = age;
	(*this).sex = sex;
	pay = 0;
}
void Person::setName(string name){
	(*this).name = name;
}
string Person::getName(){
	return name;
}
void Person::setId(int id){
	(*this).id = id;
}
int Person::getId(){
	return id;
}
void Person::setAge(int age){
	(*this).age = age;
}
int Person::getAge(){
	return age;
}
void Person::setSex(string sex){
	(*this).sex = sex;
}
string Person::getSex(){
	return sex;
}
void Person::setPay(double pay){
	(*this).pay = pay;
}
double Person::getPay(){
	return pay;
}
 void Person::print(){
	 cout<<"姓名"<<"   "<<"编号"<<"   "<<"年龄"<<"   "<<"性别"<<"   "<<"工资"<<endl;
	 cout<<name<<"   "<<id<<"   "<<age<<"   "<<sex<<"   "<<pay<<endl;
 }
 Boss::Boss(string name,int id,int age,string sex,double yearSalary):Person(name,id,age,sex){
	  (*this).yearSalary=yearSalary;
 }
void Boss::setYearSalary(double yearSalary){
	 (*this).yearSalary=yearSalary;
 }
 double Boss::getYearSalary(){
	 return yearSalary;
 }
double Boss::getPay(){
	return yearSalary/12;
}
void Boss::print(){
	 cout<<"姓名"<<"   "<<"编号"<<"   "<<"年龄"<<"   "<<"性别"<<"   "<<"工资"<<"   "<<"年薪"<<endl;
	 cout<<name<<"   "<<id<<"   "<<age<<"   "<<sex<<"   "<<pay<<"   "<<yearSalary<<endl;
 }
Employee::Employee(string name,int id,int age,string sex,double baseSalary,double award):Person(name,id,age,sex){
	(*this).baseSalary=baseSalary;
	(*this).award=award;
}
void Employee::setBaseSalary(double baseSalary){
	(*this).baseSalary=baseSalary;
}
double Employee::getBaseSalary(){
	return baseSalary;
}
void Employee::setAward(double award){
	(*this).award=award;
}
double Employee::getAward(){
	return award;
}
double Employee::getPay(){
	return baseSalary+award;
}
void Employee::print(){
	 cout<<"姓名"<<"   "<<"编号"<<"   "<<"年龄"<<"   "<<"性别"<<"   "<<"工资"<<"   "<<"基本工资"<<"   "<<"奖金"<<endl;
	 cout<<name<<"   "<<id<<"   "<<age<<"   "<<sex<<"   "<<pay<<"   "<<baseSalary<<"   "<<award<<endl;
}
HourlyWorker::HourlyWorker(string name,int id,int age,string sex,double workHour,double hourSalary):Person(name,id,age,sex){
	(*this).workHour=workHour;
	(*this).hourSalary=hourSalary;
}
void  HourlyWorker::setWorkHour(double workHour){
	(*this).workHour=workHour;
}
double HourlyWorker::getWorkHour(){
	return workHour;
}
void HourlyWorker::setHourSalary(double hourSalary){
	(*this).hourSalary=hourSalary;
}
double HourlyWorker::getHourSalary(){
	return hourSalary;
}
double HourlyWorker::getPay(){
	return workHour*hourSalary;
}
void HourlyWorker::print(){
	cout<<"姓名"<<"   "<<"编号"<<"   "<<"年龄"<<"   "<<"性别"<<"   "<<"工资"<<"   "<<"工作时间"<<"   "<<"时资"<<endl;
	 cout<<name<<"   "<<id<<"   "<<age<<"   "<<sex<<"   "<<pay<<"   "<<workHour<<"   "<<hourSalary<<endl;
}
CommWorker::CommWorker(string name,int id,int age,string sex,double baseSalary,double profit):Person(name,id,age,sex){
	(*this).baseSalary=baseSalary;
	(*this).profit=profit;
}
void CommWorker::setBaseSalary(double baseSalary){
	(*this).baseSalary=baseSalary;
}
double CommWorker::getBaseSalary(){
	 return baseSalary;
 }
void CommWorker::setProfit(double profit){
	(*this).profit=profit;
}
double CommWorker::getProfit(){
	return profit;
}	
double CommWorker::getPay(){
	return baseSalary+profit*0.15;
}
void CommWorker::print(){
	 cout<<"姓名"<<"   "<<"编号"<<"   "<<"年龄"<<"   "<<"性别"<<"   "<<"工资"<<"   "<<"基本工资"<<"   "<<"利润"<<endl;
	 cout<<name<<"   "<<id<<"   "<<age<<"   "<<sex<<"   "<<pay<<"   "<<baseSalary<<"   "<<profit<<endl;
}

void  Report::add(list<Person *> &persons,Person *p){
	persons.push_back(p);
}
void Report::print(list<Person *> persons){
	list<Person *>::iterator iter; 
	cout<<"      "<<"员工表"<<endl;
	cout<<"姓名"<<"   "<<"编号"<<"   "<<"工资"<<endl;
	for(iter=persons.begin();iter!=persons.end();iter++){
		cout<<(*iter)->getName()<<"   ";
		cout<<(*iter)->getId()<<"      ";
		cout<<(*iter)->getPay()<<endl;
	}
}