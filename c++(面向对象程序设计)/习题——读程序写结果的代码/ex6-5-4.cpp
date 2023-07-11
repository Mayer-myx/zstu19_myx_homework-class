using namespace std;
class Student{
private:
	char *name;
	int age;
	double Money;
public:
	Student(char *n="NoKnow",int Age=17,double Mey=1000.998):age(Age),Money(Mey)
	{	
		name=new char[sizeof(n)+1];
		strcpy(name,n);
	}
	operator char*(){return name;}
	operator int(){	return age;	}
	operator double(){	return Money;}
};
void main(){
	Student s1("°¢Íß¶û¹ÅÀö",19,280000.998);
	char *Name=s1;
	int  Age=s1;
	double Money=s1;
	cout<<Name<<"\t"<<Age<<"\t"<<Money<<endl;
	Student s2("Îä²ıÓã");
	Name=s2;Age=s2;Money=s2;
	cout<<Name<<"\t"<<Age<<"\t"<<Money<<endl;
}
