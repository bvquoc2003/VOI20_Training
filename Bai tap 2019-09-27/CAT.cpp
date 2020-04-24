#include <bits/stdc++.h>
using namespace std;
struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) {x=_x; y=_y;}
};
struct Line {
	Point p1, p2;
	Line() {}
	Line(Point _p1, Point _p2) {p1=_p1; p2=_p2;}
};
int m, n, t, res=1; vector <Line> a;
void Read(int i);
void Nhap();
void Extract(Point p1, Point p2, int &a, int &b, int &c) {
	a=p1.y-p2.y;
	b=p2.x-p1.x;
	c=-(a*p1.x + b*p1.y);
}

int32_t main(void) {
	freopen("CAT.OUT","w",stdout);
	Nhap();
	for (int i=0;i<t;i++) {
		bool trung=false;
		// for (int j=0;j<t;j++) if(i!=j && trungnhau(a[i],a[j])) { trung=true; break; }
		if (trung) continue;
	}
	return 0;
}

void Nhap() {
	freopen("CAT.INP","r",stdin);
	cin>>m>>n>>t;
	a.resize(t);
	for (int i=0;i<t;i++) Read(i);
	a.push_back(Line(Point(0,0),Point(0,n)));
	a.push_back(Line(Point(0,0),Point(m,0)));
	a.push_back(Line(Point(0,n),Point(m,n)));
	a.push_back(Line(Point(m,0),Point(m,n)));
	t=a.size();
}
void Read(int i) {
	int x, y;
	cin>>x>>y;
	a[i].p1=Point(x,y);
	cin>>x>>y;
	a[i].p2=Point(x,y);
}
