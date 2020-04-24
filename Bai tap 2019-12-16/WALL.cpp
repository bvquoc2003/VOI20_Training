#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="WALL";
const int N=100005;

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
    x=c-'0';
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
    if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
    if (x<0) { putchar('-'); x=-x; }
    T p=1;
    for (T temp=x/10;temp>0;temp/=10) p*=10;
    for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

typedef pair <int,int> ii;

int n, m, res=0;
int a[N], b[N];
vector <ii> ans;

bool check(int h) {
    int k=0;

    for (int i=1;i<=n;i++) {
        if (a[i]<h) {
            int ok=false;
            for (int j=k+1;j<=m;j++)
                if (a[i]+b[j]>=h) {
                    k=j;
                    ok=true;
                    break;
                }
            if (!ok) return false;
        }
    }

    return true;
}

void GetAns() {
    int k=0;
    for (int i=1;i<=n;i++)
        if (a[i]<res) {
            for (int j=k+1;j<=m;j++)
                if (a[i]+b[j]>=res) {
                    k=j;
                    break;
                }
            ans.push_back(ii(i,k));
        }
}

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(n);
    for (int i=1;i<=n;i++) 
        Read(a[i]);
    Read(m);
    for (int i=1;i<=m;i++)
        Read(b[i]);

    int l=1, r=2e8;
    while (l<=r) {
        int mid=(l+r)>>1;
        if (check(mid)) {
            res=max(res,mid);
            l=mid+1;
        } else r=mid-1;
    }

    GetAns();

    Write(res); putchar(' ');
    Write(ans.size()); putchar('\n');
    for (ii x: ans) {
        Write(x.first);
        putchar(' ');
        Write(x.second);
        putchar('\n');
    }
    return 0;
}