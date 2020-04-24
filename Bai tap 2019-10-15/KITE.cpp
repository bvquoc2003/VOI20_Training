#include <bits/stdc++.h>
using namespace std;
void compress(vector<int> &a);
int n, cnt; vector <int> a;
vector <bool> cx;
int32_t main(void) {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("KITE.INP","r",stdin);
	freopen("KITE.OUT","w",stdout);
	cin>>n; a.resize(n);
	for (int &x:a) cin>>x;
	compress(a);
	for (int i=0;i<n;i++) {
		cnt=1;
		cx.resize(n+1,true);
		for (int j=0;j<i;j++)
			if (a[i]<a[j]) {
				cnt++;
				cx[a[j]]=false;
			}
		cout<<cnt<<endl;
	}
	return 0;
}

void compress(vector<int> &a) { //Nen so
	set<int> s(a.begin(), a.end());
	vector<int> b(s.begin(), s.end());
	for (int i=0;i<a.size();++i) a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
}
