#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=500000;
#define int long long
typedef pair <int,int> ii;
int n, a[N];
priority_queue<int> q;
int res=0LL;
int32_t main(void) {
	FastIO;
	freopen("BONUS.INP","r",stdin);
	freopen("BONUS.OUT","w",stdout);
	cin>>n; n=n*n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		res+=a[i];
	}
	sort(a+1,a+1+n);
	a[n+1]=LLONG_MAX;
	int p=1, mi=LLONG_MAX;
	while (p<=n) {
		ii t=ii(a[p],1);
		while (p<n && a[p]==a[p+1]) p++, t.second++;
		mi=min(mi,t.first*t.second);
		p++;
	}
	res-=mi;
	cout<<res;
	return 0;
}