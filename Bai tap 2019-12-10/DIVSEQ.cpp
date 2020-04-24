#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

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

#define int long long
const int N=100005, mod=1000000007;
int n, a[N];
int f[N], g[N];

int32_t main() {
    FastIO;
    freopen("DIVSEQ.INP","r",stdin);
    freopen("DIVSEQ.OUT","w",stdout);
    Read(n);
    for (int i=1;i<=n;i++) Read(a[i]);
    for (int i=1;i<=n;i++) {
        if (f[i]==g[i]) {
            for (int j=1;j<=i;j++)
                if (a[j]%a[i]==0) g[a[j]]++;
        }
    }
    int res=0;
    for (int i=1;i<=n;i++) res+=f[i];
    cout<<res;
    return 0;
}