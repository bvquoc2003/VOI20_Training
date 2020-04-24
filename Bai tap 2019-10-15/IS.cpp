#include <bits/stdc++.h>
using namespace std;
struct data {
	int v, w;
	data() {v=0; w=0;}
	data(int _v, int _w) { v=_v; w=_w; }
};
bool operator < (const data &x, const data &y) {return x.v<y.v;}
void compress(vector<data> &a) { //Nen so
    set<data> s(a.begin(), a.end());
    vector<data> b(s.begin(), s.end());
    for (data &x: a) x.v=lower_bound(b.begin(),b.end(),x)-b.begin()+1;
}
int n;
vector <data> a;
int32_t main(void) {
	freopen("IS.INP","r",stdin);
	freopen("IS.OUT","w",stdout);
	cin>>n; a.resize(n);
	for (data &x: a) cin>>x.v;
	for (data &x: a) cin>>x.w;
	compress(a);
	for (data x:a) cout<<x.v<<" "<<x.w<<endl;
	return 0;
}