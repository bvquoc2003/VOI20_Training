#include <bits/stdc++.h>
#define int long long
using namespace std;
int m, n, cnt;
int32_t main(void) {
	freopen("VN.INP","r",stdin);
	freopen("VN.OUT","w",stdout);
	cin>>n>>m;
	cnt=__gcd(m,n);
	cout<<cnt<<endl;
	m/=cnt; n/=cnt;
	cout<<n<<" "<<m;
	return 0;
}