#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1005;
int n,a[N],f[N];

int main(){
	while (cin>>n && n){
		for (int i=1; i<=n; i++){
			cin>>a[i];
			f[i] = a[i];
		}
		for (int i=2; i<=n; i++)
			for (int j=1; j<i; j++)
				if (a[j]<a[i]) f[i]=max(f[i],f[j]+a[i]);
		int ans=f[1];
		for (int i=2; i<=n; i++) ans=max(ans,f[i]);
		cout<<ans<<endl;
	}
	return 0;
}
