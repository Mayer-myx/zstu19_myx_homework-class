#include <iostream>
 
using namespace std;
 
int main()
{
   int a[100],n,i;
   while(cin>>n&&n!=0)
   {
       int s=0;
       for(i=0;i<n;i++)
        cin>>a[i];
 
        s+=a[0]*6+5;
        for(i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
                s+=6*(a[i]-a[i-1])+5;
            else
                s+=4*(a[i-1]-a[i])+5;
        }
        cout<<s<<endl;
 
   }
    return 0;
}