#include <bits/stdc++.h>
using namespace std;
struct point {
	int x, y, id;
	point() {x=0; y=0; id=0;}
	point(int _x, int _y) {x=_x,y=_y;}
} origin;
typedef vector <point> Points;
bool operator < (const point &a, const point &b) {return (a.y<b.y || (a.y==b.y && a.x<b.x));}
void operator -= (point &A, point B){ A.x-=B.x; A.y-=B.y; }
bool ccw(point O, point A, point B) { A-=O, B-=O; return A.x*B.y > A.y*B.x; }
bool cmp(const point &A, point &B){ return ccw(origin, A, B); }
double Area(Points a) {
	size_t n=a.size();
	point tmp=a[n-1];
	a.insert(a.begin(),tmp);
	a.push_back(a[1]);
	double res=0.0;
	for (size_t i=1;i<=n;i++) res+=(a[i+1].x-a[i].x)*(a[i+1].y+a[i].y);
	res=abs(res)/2.0;
	return res;
}
double res=0;
int n; point a;
int32_t main(void){
	freopen("SAW.INP","r",stdin);
	freopen("SAW.OUT","w",stdout);
	int T; cin>>T;
	while (T--) {
		cin>>n;
		int Min=INT_MAX;
		for (int i=1;i<=n+1;i++) {
			int x, y; cin>>x>>y;
			if (x+y<Min) {
				Min=x+y;
				a=point(x,y);
			}
		}
		res=max(res,abs(a.x+a.y)*2.0);
	}
	cout<<fixed<<setprecision(6)<<res;
	return 0;
}
