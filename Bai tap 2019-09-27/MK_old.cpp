#include <bits/stdc++.h>
using namespace std;
int n, res=0;
vector <string> a;
bool cmp (const string &a, const string &b) {return a.length()<b.length();}
int32_t main() {
	freopen("MK.INP","r",stdin);
	freopen("MK.OUT","w",stdout);
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin>>n; a.resize(n+1);
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end(), cmp);
	// for (int i=1;i<=n;i++) cout<<a[i]<<endl;
	for (int i=1;i<n;i++)
	for (int j=i+1;j<=n;j++) {
		if (a[j].find(a[i])!=-1) {
			res++;
			if (a[i].length()==a[j].length()) res++;
		}
	}
	cout<<res;
	return 0;
}