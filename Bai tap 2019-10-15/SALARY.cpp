#include <bits/stdc++.h>
using namespace std;
typedef vector <int> List;
int n, m; char ch;
vector <List> l;
vector <int64_t> a;
void Update(int A, int64_t x) {
	if (l[A].empty()) return;
	for (int tt:l[A]) {
		a[tt]+=x;
		Update(tt,x);
	}
}
int A; int64_t x;
int32_t main(void) {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("SALARY.INP","r",stdin);
	freopen("SALARY.OUT","w",stdout);
	cin>>n>>m;
	a.resize(n+1);
	l.resize(n+1);
	cin>>a[1];
	for (int i=2;i<=n;i++) {
		cin>>a[i];
		cin>>x;
		l[x].push_back(i);
	}
	while (m--) {
		cin>>ch>>A;
		if (ch=='p' || ch=='P') {
			cin>>x;
			Update(A,x);
			continue;
		}
		cout<<a[A]<<endl;
	}
	return 0;
} 