#include <bits/stdc++.h>
using namespace std;
int n; vector <int> a;
int32_t main(void) {
	freopen("Pinocchio.inp","r",stdin);
	freopen("Pinocchio.out","w",stdout);
	cin>>n; a.resize(n);
	for (int& x:a) cin>>x;
	int gcd=a[0];
	for (int x:a) gcd=__gcd(gcd,x);
	cout<<gcd;
	return 0;
}