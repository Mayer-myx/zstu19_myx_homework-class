#include <iostream>

using namespace std;

int period(int a, int b)
{
    int t = 0, f1 = 1, f2 = 1, temp;
    if (a == 0 || b == 0)
        return 12;
    if ((a + b) % 7 == 1)
        return 1;
    while (1)
    {
        temp = (a * f1 + b * f2) % 7;
        f2 = f1;
        f1 = temp;
        t++;
        if (f1 == 1 && f2 == 1)     /*再次遇到f1 = 1，f2 = 1的时候跳出*/
            break;
    }
    return t;
}
int main()
{
    int a, b, n, f1, f2, temp;
    while (cin>>a>>b>>n, a, b, n)
    {
        if (a % 7 == 0 && b % 7 == 0)
        {
            cout<<(n<3)<<endl;
            continue;
        }
        f1 = 1, f2 = 1;
        if (n > 20)
            n = (n - 20) % period(a % 7, b % 7) + 20;
        if (n > 2)
            n -= 2;
        else n = 0;
        while (n--)
        {
            temp = (a * f1 + b * f2) % 7;
            f2 = f1;
            f1 = temp;
        }
        cout<<f1<<endl;
    }
    return 0;
}
