# include"calculator.h"
void main()
{
	int count=0;
    calculator cal(0,0,'+');
	while(1){
		cout<<"��������Ҫ���еĲ�����+��-��*��/��%,#."<<endl;
		cout<<"#�����������."<<endl;
		cin>>cal.c;
		if(cal.c=='#')
	{
		break;
	}
	else
	{
		count++;
	}
		cout<<"��������������"<<endl;
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
	cout<<"��һ��������"<<count<<"�β���"<<endl;
	system("pause");
}