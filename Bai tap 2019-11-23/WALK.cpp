#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int64_t n,r; vector <int64_t> a;
int32_t main(void) {
	FastIO;
	freopen("WALK.INP","r",stdin);
	freopen("WALK.OUT","w",stdout);
	cin>>n>>r;
	int cnt=0;
	while (cin>>n) {
		cnt++;
		a.push_back(n);
	}
	n=a.size();
	sort(a.begin(),a.end());
	int64_t res=0LL;
	// for (int i=0;i<12;i++) cout<<a[i]<<" ";
	for (int i=0;i<n;i++) {
		vector<int64_t>::iterator it=lower_bound(a.begin()+i,a.end(),a[i]+r+1);
		if (it==a.end()) continue;
		int64_t p=it-a.begin();
		// cout<<i<<" "<<a[i]<<" "<<*it<<" "<<p<<endl;
		if (p<n && p>i && *it-a[i]>r) res+=abs(n-p);
	}
	cout<<res;
	return 0;
}