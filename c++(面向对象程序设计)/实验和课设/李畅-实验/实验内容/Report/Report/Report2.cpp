# include "ReportH.h"
void main(){
	list<Person *> persons;
	Person (*p)=new Boss("����",1,32,"boy",12000);
	Person (*p1)=new Employee("����",2,24,"boy",1200,200);
	Person (*p2)=new HourlyWorker("����",3,25,"boy",1240,10);
	Person (*p3)=new CommWorker("С��",4,26,"boy",1200,2400);
	Report r;
	r.add(persons,p);
	r.add(persons,p1);
	r.add(persons,p2);
	r.add(persons,p3);
	r.print(persons);
	system("pause");
}