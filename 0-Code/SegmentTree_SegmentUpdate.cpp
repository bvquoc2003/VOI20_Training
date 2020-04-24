#include <bits/stdc++.h>
using namespace std;
int n, m;
struct SegmentTree {
	vector <int64_t> st;
	SegmentTree() {st.clear();}
	SegmentTree(int n) { st.resize((4*(n+5))); }
	void update(int id, int l, int r, int i, int v) {
		if (i<l || r<i) return;
		if (l==r) {
			st[id]+=v;
			return;
		}
		int mid = (l+r)>>1, id1=id<<1, id2=id1+1;
		update(id1,l,mid,i,v);
		update(id2,mid+1,r,i,v);
		st[id]=st[id1]+st[id2];
	}
	int64_t get(int id, int l, int r, int u, int v) {
		if (v<l || r<u) return 0;
		if (u<=l && r<=v) return st[id];
		int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
		return get(id<<1,l,mid,u,v)+get(id2,mid+1,r,u,v);
	}
};
int32_t main(void) {
	freopen("UQSEQ.INP","r",stdin);
	freopen("UQSEQ.OUT","w",stdout);
	cin>>n>>m;
	SegmentTree ST(n);
	while (m--) {
		char ch; cin>>ch;
		if (ch=='I' || ch=='i') {
			int l, r, x;
			cin>>l>>r>>x;
			ST.update(1,1,n,l,x);
			ST.update(1,1,n,r+1,-x);
		} else {
			int x; cin>>x;
			cout<<ST.get(1,1,n,1,x)<<endl;
		}
	}
	return 0;
}
