#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
string n, s="";
int l;
int32_t main(void) {
	FastIO;
	freopen("NUMBER68.INP","r",stdin);
	freopen("NUMBER68.OUT","w",stdout);
	cin>>n; l=n.length();
	if (n[0]<'6') s="0", l--;
	
	cout<<s;
	return 0;
}