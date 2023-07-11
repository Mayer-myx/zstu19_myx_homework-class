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
	cout<<"该电梯一共10层"<<"当前您在"<<nowfloor<<"楼"<<endl;
	cout<<"请选择操作"<<endl;
	cout<<"1、上升"<<endl;
	cout<<"2、下降"<<endl;
	}
	void run(){
		int m,i,n=Maxfloor;
		cin>>m;
		if(m==rise){
			cout<<"请输入要进入的楼层："<<endl;
             cin>>nextfloor;
			 if(nextfloor<=nowfloor||nextfloor>10||nextfloor<=0){
				 cout<<"error"<<endl;
			 }
			 else{
				 for(i=nowfloor;i<nextfloor;i++)
				 cout<<i<<endl;
			 cout<<"第"<<nextfloor<<"层到了"<<endl;
			 nowfloor=nextfloor;
			 }
		}
	    else if(m==fall){
			 cout<<"请输入要进入的楼层："<<endl;
			 cin>>nextfloor;
			 cout<<endl<<endl;
			 if(nextfloor>=nowfloor||nextfloor>10||nextfloor<=0){
				 cout<<"error"<<endl;
			 }
			 else{
				 for(i=nowfloor;i>nextfloor;i--)
				 cout<<i<<endl;
			 cout<<"第"<<nextfloor<<"层到了"<<endl;
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
