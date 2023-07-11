# include<iostream>
# include<cstdlib>
using namespace std;
class calculator{
public:
 double a,b;
 char c;

public:
	calculator(double a,double b,char c);
    void add(calculator cal);
    void subduction (calculator cal);
    void multiplicative(calculator cal);
    void division(calculator cal);
    void residue(calculator cal);
};