#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y, id;
	point() {x=0; y=0; id=0;}
	point(int _x, int _y) {x=_x,y=_y;}
};
bool operator < (const point &a, const point &b) {return (a.y<b.y || (a.y==b.y && a.x<b.x));}
void operator -= (point &A, point B){ A.x-=B.x; A.y-=B.y; }
bool ccw(point O, point A, point B) { A-=O, B-=O; return A.x*B.y > A.y*B.x; }
point origin;
bool cmp(const point &A, point &B){ return ccw(origin, A, B); }
typedef vector <point> Points;
int n;
Points a;
int32_t main(void){
	freopen("RAOCAY.INP","r",stdin);
	freopen("RAOCAY.OUT","w",stdout);
	cin>>n; a.resize(n+2);
	for (int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].y;
		a[i].id=i;
	}
	sort(a.begin()+1,a.end()-1);
	origin=a[1];
	sort(a.begin()+2,a.end()-1,cmp);
	a[0]=a[n]; a[n+1]=a[1]; int j=1;
	for (int i=1; i<=n+1; i++) {
		while (j>2 && !ccw(a[j-2],a[j-1],a[i])) j--;
		a[j++]=a[i];
	}
	n=j-2;
	cout<<n<<endl;
	for (int i=1;i<=n;i++) cout<<a[i].id<<" ";
	return 0;
}
