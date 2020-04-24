#include <bits/stdc++.h>
using namespace std;
void Solve(int n) {
	int64_t res=0;
	for (int i=1;i<n;i++) for (int j=i+1;j<=n;j++) res+=__gcd(i,j);
	cout<<res<<endl;
}
int32_t main(void) {
	freopen("sumgcd.inp","r",stdin);
	freopen("sumgcd.out","w",stdout);
	int T; cin>>T;
    while(T--) {
		int n; cin>>n;
		Solve(n);
	}
}

/*
#include <bits/stdc++.h>
#define MaxN 1000006
using namespace std;
int n, p[MaxN];
    long long f[MaxN],t[MaxN];
void Solve() {
	n=1000000;
	for(int j=2; j<=n; j++) p[j]=j;
	for(int i=2; i<=n; i++)
	if(p[i]==i) for(int j=i; j<=n; j+=i) p[j]-=p[j]/i;
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i) f[j]+=(int64_t)i*p[j/i];
	for(int j=1; j<=n; j++) t[j]=t[j-1]+f[j];
}
int32_t main(void) {
	freopen("sumgcd.inp","r",stdin);
	freopen("sumgcd.out","w",stdout);
	Solve();
	int T; cin>>T;
    while(T--) {
		cin>>n;
		cout<<t[n]<<"\n";
	}
}
*/