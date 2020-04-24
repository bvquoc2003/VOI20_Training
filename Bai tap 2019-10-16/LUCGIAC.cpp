#include <bits/stdc++.h>
using namespace std;
const double eps=0.0001;
struct Point{
	double x,y;
	Point() {x=0; y=0;}
	Point(double _x, double _y) {x=_x; y=_y;}
};
typedef vector<Point> Polygon;
double Dist(Point p1, Point p2) { return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)); }
bool DaGiacDeu(Polygon p) {
	int n=p.size(), dt=n-1;
	vector <double> kc;
	for (int i=0;i<n-1;i++) for (int j=i+1;j<n;j++) kc.push_back(Dist(p[i],p[j]));
	sort(kc.begin(),kc.end());
	n=kc.size();
	for (int i=0;i<n-1;) {
		int j=(i+dt<n?i+dt:n-1);
		// cout<<kc[i]<<" "<<kc[j]<<endl;
		// cout<<(abs(kc[i]-kc[j])<=eps)<<endl;
		if (abs(kc[i]-kc[j])>eps) return false;
		i=j+1;
	}
	return true;
}
Polygon p(6);
int32_t main(void) {
	freopen("LUCGIAC.INP","r",stdin);
	freopen("LUCGIAC.OUT","w",stdout);
	for (Point& x:p) cin>>x.x>>x.y;
	cout<<(DaGiacDeu(p)?"YES":"NO");
	return 0;
}