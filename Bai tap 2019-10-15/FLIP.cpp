#include <bits/stdc++.h>
using namespace std;
struct coin{
	bool stt;
	int a, b;
	coin() {stt=1; a=0; b=0;}
	coin(int _stt, int _a, int _b) {stt=_stt; a=_a; b=_b;}
	int GetVal() {return (stt==1?a:b);}
};
typedef vector<coin> coins;
int n, t;
coins d;
int32_t main(void) {
	freopen("FLIP.INP","r",stdin);
	freopen("FLIP.OUT","w",stdout);
	cin>>n>>t; d.resize(n);
	for (coin &x:d) cin>>x.a>>x.b;
	// for (coin x:d) cout<<x.stt<<" "<<x.a<<" "<<x.b<<endl;
	while (cin>>t) for (coin &x:d) if (x.GetVal()<=t) x.stt=!x.stt;
	for (coin x:d) cout<<x.GetVal()<<" ";
	return 0;
}