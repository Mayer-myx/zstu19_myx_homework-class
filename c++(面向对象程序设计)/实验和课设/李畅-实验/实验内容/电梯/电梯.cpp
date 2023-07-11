# include <iostream>
# include <string>
# include <cstdlib>
# include <cstdio>
using namespace std;
void main(){
	ElevatorFactory elevator(1);
	while(1){
		cout<<"�˵���һ��ʮ��"<<endl;
		cout<<"��ǰ����Ϊ"<<ele.getNow()<<endl;
		cout<<"-----��ѡ�����-----:"<<endl;
		cout<<endl<<endl;
		cout<<"  1�������밴1;2���½��밴2"<<endl;
		cout<<endl<<endl;
		cout<<"---------------"<<endl;
		cin>>choice;
		cout<<"�����������������"<<endl;
		cin>>num;
		elevator.input(num);
		elevator.setlevel(choice,num);
	}
}
class Person{
public:
	Person(){}
	void input(int num){
		int i;
		for(int i=0;i<num;i++){
			cout<<"���������ڵ�¥��,������Ҫȥ��¥��"<<endl;
			cin>>level[i-1];
	}
	int level[20];
};
class Elevator{
	int nowlevel,nextlevel,max,num;
public:
	elevator(int nowlevel=1,int max=10){
		(this)->nowlevel=nowlevel;
		(this)->max=max;
	}
	char choice;
	
	void up(){
		int j;
		cout<<"---������Ҫ�����¥��---"<<endl;
		cin>>next;
		if(next<=now||next>max||next<1){
			cout<<"��¥�㲻����"<<endl;
			choice=0;
		}
		else{
			for(j=now;j<=next;j++){
				cout<<endl<<"--"<<j<<"--"<<endl<<endl;
			}
			cout<<"��"<<next<<"�㵽��"<<endl;
			now=next;
		}
	}
	void down(){
		int j;
		cout<<"---������Ҫ�����¥��---"<<endl;
		cin>>next;
		if(next>=now||next>max||next<1){
			cout<<"��¥�㲻����"<<endl;
			choice=0;
		}
		else{
			for(j=now;j>=next;j--){
				cout<<endl<<"--"<<j<<"--"<<endl<<endl;
			}
			cout<<"��"<<next<<"�㵽��"<<endl;
			now=next;
		}
	}
	}
};
class ElevatorFactory:public Elevator,public Person{
public:
	void upcompare();
	void downcompare();
	void setlevel();
	int outlevel;
	ElevatorFactory(){outlevel=1};
	void ElevatorFactory::upcompare(int number){
		int i,j,temp;
		for(i=0;i<2*number-1;i++)
			for(j=i;j<2*number-1;j++){
				if(level[i]>level[j]){
					temp=level[i];
					level[i]=level[j];
					level[j]=temp;
				}
			}
			outlevel=level[i];
	}
	void ElevatorFactory::downcompare(int number){
		int i,j,temp;
		for(i=0;i<2*number-1;i++)
			for(j=i;j<2*number-1;j++){
				if(level[i]<level[j]){
					temp=level[i];
					level[i]=level[j];
					level[j]=temp;
				}
			}
			outlevel=level[i];
	}
	void ElevatorFactory::setlevel(char choice,int num){
		switch(choice){
			case'1':
				upcompare(n);
				for(i=0;i<2*num;i++)
					up(level[i]);
				break;
			case'2':
				downcompare(n);
				for(i=0;i<2*n;i++)
					down(level[i]);
				break;
			default:
				cout<<"--���������������������--"<<endl;
				cout<<endl<<endl;
				cout<<"  1�������밴1��2���½��밴2"<<endl;
				cout<<endl<<endl;
				cout<<"----------------"<<endl;
				continue;
				break;
		}
	}
};
