#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

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

const int N=1000006;
int n, d, a[N];
int res, psum[N];
vector <int> c;

int32_t main() {
    FastIO;
    freopen("DIVSEQ.INP","r",stdin);
    freopen("DIVSEQ.OUT","w",stdout);
    int T; Read(T);
    while (T--) {
        Read(d); Read(n);
        c.assign(d,0);
        for (int i=1;i<=n;i++) {
            Read(a[i]);
            a[i]=a[i-1]+a[i];
            c[a[i]%d]++;
        }
        res=c[0];
        for (int i=0;i<d;i++) {
            res+=(c[i]*(c[i]-1))/2;
        }
        Write(res);
        putchar('\n');
    }
    return 0;
}