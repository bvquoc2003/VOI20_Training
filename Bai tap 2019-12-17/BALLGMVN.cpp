#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define val first
#define id second
#define x first
#define y second

const string INP=".INP", OUT=".OUT";
const string FILENAME="BALLGMVN";
const int N=2003;
const double oo=999999.0;
typedef pair <double,int> p_di;
typedef pair <int,int> p_ii;

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
    x=c-'0';
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
    if (Neg) x=-x;
}

int n; p_di a[N];
p_ii d[N];

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);

    Read(n);
    for (int i=1;i<=2*n;i++) {
        Read(d[i].x);
        Read(d[i].y);
    }

    for (int i=1;i<=n;i++) {
        for (int j=n+1;j<=2*n;j++) {
            double u=d[j].x-d[i].x, v=d[j].y-d[i].y;
            a[j].id=j;
            if (v!=0.0) a[j].val=u/v;
            else a[j].val=oo;
        }
        sort(a+n+1,a+n*2+1,[](const p_di &a, const p_di &b) {
            return (a.val<b.val);
        });
        for (int j=n+2;j<=(2*n);j++) {
            if (a[j].val==a[j-1].val) {
                cout<<i<<" "<<a[j-1].id<<" "<<a[j].id;
                return 0;
            }
        }
    }

    for (int i=n+1;i<=n*2;i++) {
        for (int j=1;j<=n;j++) {
            double u=d[j].x-d[i].x, v=d[j].y-d[i].y;
            a[j].id=j;
            if (v!=0.0) a[j].val=u/v;
            else a[j].val=oo;
        }
        sort(a+1,a+1+n,[](const p_di &a, const p_di &b) {
            return (a.val<b.val);
        });
        for (int j=2;j<=n;j++) {
            if (a[j].val==a[j-1].val) {
                cout<<a[j-1].id<<" "<<a[j].id<<" "<<i;
                return 0;
            }
        }
    }

    cout<<"-1";
    return 0;
}