#include <bits/stdc++.h>
using namespace std;
struct MaxST{
	vector <int> st, gt;
	MaxST() {}
	MaxST(int n) {
		st.resize((4*(n+5)));
		gt.resize(n+1);
	}
	void update(int id, int l, int r, int i, int v) {
	    if (i < l || r < i) return;
	    if (l==r) {
	        st[id]=v;
	        gt[i]=v;
	        return;
	    }
	    int mid = (l+r)>>1, id1=id<<1, id2=id1+1;
	    update(id1,l,mid,i,v);
	    update(id2,mid+1,r,i,v);
	    st[id]=max(st[id1],st[id2]);
	}
	int getmax(int id, int l, int r, int u, int v) {
	    if (v < l || r < u) return INT_MIN;
	    if (u <= l && r <= v) return st[id];
	    int mid = (l+r)>>1, id1=id<<1, id2=id1+1;
	    return max(getmax(id<<1,l,mid,u,v), getmax(id2, mid+1, r, u, v));
	}
};
int n, m, x, y;
char ch;
int32_t main(void) {
	freopen("QUERY.INP","r",stdin);
	freopen("QUERY.OUT","w",stdout);
	cin>>n>>m;
	MaxST T(n);
	while (m--) {
		cin>>ch>>x>>y;
		if (ch=='S' || ch=='s') T.update(1,1,n,x,y);
		else cout<<T.getmax(1,1,n,x,y)<<endl;
	}
	return 0;
}