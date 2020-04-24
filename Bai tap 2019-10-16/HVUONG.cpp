#include <bits/stdc++.h>
using namespace std;
const double eps=0.0001;
int n, m;
int64_t res=0;
int32_t main(void) {
	freopen("HVUONG.INP","r",stdin);
	freopen("HVUONG.OUT","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=min(m,n);i+=2) res+=int64_t(i)*(m-i+1)*(n-i+1);
	cout<<res;
	return 0;
}