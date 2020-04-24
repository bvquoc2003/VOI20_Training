#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const string INP=".INP", OUT=".OUT";
const string FILENAME="ATTACK";
const int N=100005, INF=9000000000000000000;

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

int n, k, a[N], b[N], res=INF;

bool check(int x) {
    int s=0;
    for (int i=1;i<=n;i++) {
        int q=x-a[i];
        if (q<0) continue;
        s+=(q/b[i]+1);
        if (s>k) return true;
    }
    return s>k;
}

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(n); Read(k);
    for (int i=1;i<=n;i++) {
        Read(a[i]);
        Read(b[i]);
    }

    int l=0, r=1e18;
    while (l<=r) {
        int mi=(l+r)>>1;
        if (check(mi)) {
            res=mi;
            r=mi-1;
        } else l=mi+1;
    }

    Write(res);
    return 0;
}