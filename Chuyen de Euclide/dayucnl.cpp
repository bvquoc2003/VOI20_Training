#include <bits/stdc++.h>
using namespace std;
int lcm(int _a, int _b) {return (_a*_b)/__gcd(_a,_b);}
int n; vector <int> a;
int32_t main() {
	freopen("dayucnl.inp","r",stdin);
	freopen("dayucnl.out","w",stdout);
	int T; cin>>T;
	while (T--) {
		cin>>n; a.resize(n);
		for (int& x:a) cin>>x;
		cout<<a[0]<<" ";
		for (int i=1;i<n;i++) cout<<lcm(a[i],a[i-1])<<" ";
		cout<<a[n-1]<<endl;
	}
	return 0;
}