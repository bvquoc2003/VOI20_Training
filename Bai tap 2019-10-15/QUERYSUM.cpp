#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
inline int ReadInt() {
	char ch;
	while (ch=getchar(), ch<'0' || ch>'9');
	int res=ch-'0';
	while (ch=getchar(), ch>='0' && ch<='9') res = res * 10 + ch - '0';
	return res;
}
void WriteInt(int64_t x) {
	if (x>9) WriteInt(x/10);
	putchar(x%10+'0');
}
struct SumST{
	vector <int> gt;
	vector <int64_t> st;
	SumST() {st.clear(); gt.clear();}
	SumST(int n) {
		st.resize((4*(n+5)));
		gt.resize(n+1);
	}
	void update(int id, int l, int r, int i, int v) {
	    if (i<l || r<i) return;
	    if (l==r) {
	        st[id]=v;
	        gt[i]=v;
	        return;
	    }
	    int mid = (l+r)>>1, id1=id<<1, id2=id1+1;
	    update(id1,l,mid,i,v);
	    update(id2,mid+1,r,i,v);
	    st[id]=st[id1]+st[id2];
	}
	int64_t getsum(int id, int l, int r, int u, int v) {
	    if (v<l || r<u) return 0;
	    if (u<=l && r<=v) return st[id];
	    int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
	    return getsum(id<<1,l,mid,u,v)+getsum(id2,mid+1,r,u,v);
	}
};
int n, m, x, y;
char ch;
int32_t main(void) {
	FastIO;
	freopen("QUERYSUM.INP","r",stdin);
	freopen("QUERYSUM.OUT","w",stdout);
	cin>>n>>m;
	SumST T(n);
	while (m--) {
		cin>>ch>>x>>y;
		if (ch=='S' || ch=='s') T.update(1,1,n,x,y);
		else cout<<T.getsum(1,1,n,x,y)<<endl;
	}
	return 0;
}