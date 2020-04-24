// https://www.spoj.com/THPTCBT/problems/MTKC/
#include <bits/stdc++.h>
#define epsilon 0.00001
using namespace std;
struct Point {
	double x, y;
	Point() { x = y = 0.0; }
	Point(double _x, double _y) {x=_x; y=_y;}
};
typedef vector <Point> Polygon;
long double Dist(Point p1, Point p2) { return sqrt((long double)((p1.x-p2.x)*(p1.x-p2.x))+(long double)((p1.y-p2.y)*(p1.y-p2.y))); }
int n; Point X, z;
long double res=999999999999999999999999.9;
Polygon p;
double a,b,c;
void PTDT(Point p1, Point p2) {
	a=p2.y-p1.y;
	b=p1.x-p2.x;
	c=(p2.x*p1.y-p1.x*p2.y);
}
bool pthdgd(Point &z, double a1, double b1, double c1, double a2, double b2, double c2) {
	double d, dx, dy;
	d=a1*b2-a2*b1;
	dx=c2*b1-c1*b2;
	dy=a1*c2-a2*c1;
	if (abs(d)<=epsilon) return false;
	z=Point(dx/d,-dy/d);
	return true;
}
int ccw(Point a, Point b, Point m) {
	long double k=(long double)((b.x-a.x)*(m.y-b.y))-(long double)((m.x-b.x)*(b.y-a.y));
	if (abs(k)<epsilon) return 0;
	if (k>0) return 1;
	return -1;
}
bool ok(Point m, Point a, Point b) {
	return( (ccw(a,b,m)==0)  && (min(a.x,b.x)<=m.x) && (m.x<=max(a.x,b.x)) && (min(a.y,b.y)<=m.y) && (m.y<=max(a.y,b.y)) );
}
int32_t main(void) {
	freopen("BILL.INP","r",stdin);
	freopen("BILL.OUT","w",stdout);
	cin>>n>>X.x>>X.y;
	p.resize(n+2);
	for (int i=1;i<=n;i++) {
		cin>>p[i].x>>p[i].y;
		res=min(res,Dist(X,p[i]));
	}
	p[0]=p[n]; p[n+1]=p[1];
	for (int i=1;i<=n;i++) {
		PTDT(p[i],p[i+1]);
		bool k=pthdgd(z,a,b,c,-b,a,-(-b*X.x+a*X.y));
		if (!k) continue;
		if (ok(z,p[i],p[i+1])) res=min(res,Dist(z,X));
	}
	cout<<fixed<<setprecision(4)<<res;
	return 0;
}