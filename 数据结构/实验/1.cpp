# include<iostream>
using namespace std;
class elevator{
private:
	    int rise;
		int fall;
		int nowfloor;
		int nextfloor;
public:
	elevator(int m=1,int n=2,int j=1){
		rise=m;fall=n;nowfloor=j;
	}
	void print(){
	cout<<"�õ���һ��10��"<<"��ǰ����"<<nowfloor<<"¥"<<endl;
	cout<<"��ѡ�����"<<endl;
	cout<<"1������"<<endl;
	cout<<"2���½�"<<endl;
	}
	void run(){
		int m,i,n=Maxfloor;
		cin>>m;
		if(m==rise){
			cout<<"������Ҫ�����¥�㣺"<<endl;
             cin>>nextfloor;
			 if(nextfloor<=nowfloor||nextfloor>10||nextfloor<=0){
				 cout<<"error"<<endl;
			 }
			 else{
				 for(i=nowfloor;i<nextfloor;i++)
				 cout<<i<<endl;
			 cout<<"��"<<nextfloor<<"�㵽��"<<endl;
			 nowfloor=nextfloor;
			 }
		}
	    else if(m==fall){
			 cout<<"������Ҫ�����¥�㣺"<<endl;
			 cin>>nextfloor;
			 cout<<endl<<endl;
			 if(nextfloor>=nowfloor||nextfloor>10||nextfloor<=0){
				 cout<<"error"<<endl;
			 }
			 else{
				 for(i=nowfloor;i>nextfloor;i--)
				 cout<<i<<endl;
			 cout<<"��"<<nextfloor<<"�㵽��"<<endl;
			 cout<<endl<<endl;
			 nowfloor=nextfloor;
			 }
		}
		else 
			cout<<"error"<<endl;
	}
};
void main(){
	elevator a;
	while(1){
	a.print();
	a.run();
	}
}
