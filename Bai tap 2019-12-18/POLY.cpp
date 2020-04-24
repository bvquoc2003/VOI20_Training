#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long
#define double long double
#define x first
#define y second

const string INP=".INP", OUT=".OUT";
const string FILENAME="POLY";

typedef pair<int,int> point;
typedef vector <point> Points;
void operator -= (point &A, point B){ A.x-=B.x; A.y-=B.y; }
bool ccw(point O, point A, point B) { A-=O, B-=O; return A.x*B.y > A.y*B.x; }
point origin;
bool cmp(const point &A, point &B){ return ccw(origin, A, B); }
double Area(point a, point b, point c) {
    point p[5];
    p[1]=a; p[2]=b; p[3]=c; p[4]=a;
    double s=0.0;
    for (int i=1;i<=3;i++) s+=(p[i+1].x-p[i].x)*(p[i+1].y+p[i].y);
    s=(double)(abs(s))/2.0;
    return s;
}

int n, k; Points a, CVH;
double res=0.0;
Points ans;

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    cin>>n>>k; a.resize(n+2);
    if (n<3) {
        cout<<"0.00";
        return 0;
    }
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    //Find Convex Hull
    sort(a.begin()+1,a.end()-1);
    origin=a[1];
    sort(a.begin()+2,a.end()-1,cmp);
    a[0]=a[n]; a[n+1]=a[1]; int j=1;
    for (int i=1; i<=n+1; i++) {
        while (j>2 && !ccw(a[j-2],a[j-1],a[i])) j--;
        a[j++]=a[i];
    }
    for (int i=1;i<=j-2;i++) CVH.push_back(a[i]);
    // Solve
    for (int i=0;i<CVH.size()-2;i++) {
        int k=i+2;
        for (int j=i+1;j<CVH.size()-1;j++) {
            double s=Area(CVH[i],CVH[j],CVH[k]);
            while (k<CVH.size()-1) {
                double _s=Area(CVH[i],CVH[j],CVH[k+1]);
                if (s<_s) {
                    s=_s;
                    k++;
                } else break;
            }
            res=max(res,s);
        }
    }
    cout<<fixed<<setprecision(2)<<res;
    return 0;
}