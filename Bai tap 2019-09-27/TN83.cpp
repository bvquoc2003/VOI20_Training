#include <bits/stdc++.h>
using namespace std;
int n, x, res=1;
vector<int> a;
int32_t main() {
	freopen("TN83.INP","r",stdin);
	freopen("TN83.OUT","w",stdout);
	cin>>n; a.push_back(0);
	for (int i=1;i<=n;i++) {
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin()+1,a.end());
	a[n]++;
	for (int i=n-1;i>0;i--) {
		x=a[i]+n;
		if (x>=a[i+1]) {
			res++;
			a[i]=max(a[i+1],a[i]+n-i+1);
		} else break;
	}
	cout<<res;
	return 0;
}