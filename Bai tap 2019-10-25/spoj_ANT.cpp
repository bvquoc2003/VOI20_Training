#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define int int64_t
using namespace std;
int t=0;
size_t n, m;
vector<int> a, b;
int32_t main(void) {
    FastIO;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
	a.resize(n+1);
	for (size_t i=1;i<=n;i++) a[i]=i;
	for (size_t i=1;i<=n;i++){
		t+=m;
		t%=a.size()-1;
		if (t==0) t=a.size()-1;
		b.push_back(a[t]);
		a.erase(a.begin()+t--);
	}
	for (size_t i=0;i<n;i++) 
    if (b[i]==n) {
        cout<<i+1;
        break;
    }
    return 0;
}