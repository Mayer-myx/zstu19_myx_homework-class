# include"calculator.h"
void main()
{
	int count=0;
    calculator cal(0,0,'+');
	while(1){
		cout<<"请输入你要进行的操作：+，-，*，/，%,#."<<endl;
		cout<<"#代表结束操作."<<endl;
		cin>>cal.c;
		if(cal.c=='#')
	{
		break;
	}
	else
	{
		count++;
	}
		cout<<"请输入两个数："<<endl;
		cin>>cal.a>>cal.b;
	switch(cal.c){
	case '+':cal.add(cal);
		break;
	case '-':cal.subduction (cal);
		break;
	case '*':cal.multiplicative(cal);
		break;
	case '/':cal.division(cal);
		break;
	case '%':cal.residue(cal);
	default:
		break;
	}
}
	cout<<"你一共进行了"<<count<<"次操作"<<endl;
	system("pause");
}