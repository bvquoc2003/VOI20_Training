#include <bits/stdc++.h>
#define int long long
using namespace std;
int m, n, res;
int32_t main(void) {
	freopen("SHARE.INP","r",stdin);
	freopen("SHARE.OUT","w",stdout);
	cin>>n>>m;
	res=m-__gcd(m,n);
	cout<<res;
	return 0;
}