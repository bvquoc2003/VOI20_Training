#include <bits/stdc++.h>
using namespace std;
struct Circle { int l, r; };
int n, res=1; 
vector<Circle> a;
bool operator <(const Circle &a, const Circle &b) {return (a.l<b.l || (a.l==b.l && a.r>b.r));}
vector<int> h;
void Nhap() {
	freopen("CIRCLE.INP","r",stdin);
	cin>>n; res=n;
	a.resize(n+1);
	h.resize(n+5);
	int r,c;
	for (int i=1;i<=n;i++) {
		cin>>c>>r;
		a[i].l=c-r;
		a[i].r=c+r;
	}
}
void ChatNhiphan() {
	sort(a.begin()+1,a.end());
    h[0]=INT_MIN;
    for (int i=1;i<=n;i++) h[i]=INT_MAX;
    for (int i=1;i<=n;i++) {
        int l=01, r=n;
        while (l<=r) {
            int mid=(l+r)/2;
            if (h[mid]>=a[i].r) r=mid-1;
            else l=mid+1;
        }
        h[r+1]=a[i].r;
    }
}
void Xuat() {
	freopen("CIRCLE.OUT","w",stdout);
    for (int i=n;i>0;i--)
    if (h[i]!=INT_MAX) {
        res=i;
        break;
    }
    res=n-res;
    cout<<res;
}
int32_t main(void) {
	Nhap();
	ChatNhiphan();
	Xuat();
	return 0;
}