#include <bits/stdc++.h>
using namespace std;
int64_t n, res;
vector <int64_t> a;
int32_t main(void) {
	freopen("tn.inp","r",stdin);
	freopen("tn.out","w",stdout);
	cin>>n; a.resize(n);
	for (int64_t& x:a) cin>>x;
	int64_t gcd=1;
	for (int64_t x:a) {
		res=gcd*x;
		gcd=__gcd(gcd,x);
		res/=gcd;
		gcd=res;
	}
	cout<<res<<"\n";
	for (int64_t x:a) cout<<res/x<<" ";
	return 0;
}