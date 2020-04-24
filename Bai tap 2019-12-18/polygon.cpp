#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

typedef vector<int> vi;
typedef pair<int, int> pii;

const string INP=".INP", OUT=".OUT";
const string FILENAME="POLYGON";
const int N=5003, base=1e9+7;

int n, a[N+10], p[N+10], f[N+10][N+10];

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);

    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    p[0]=1;
    for (int i=1;i<=N;i++) 
        p[i]=(p[i-1]*2)%base;

    for (int i=0;i<=n;i++)
        f[i][0]=1;
    
    for (int i=1;i<=n;i++)
        for (int j=1;j<=N;j++) {
            f[i][j]=f[i-1][j];
            if (j>=a[i]) f[i][j]=(f[i][j]+f[i-1][j-a[i]])%base;
        }

    int res=0;
    for (int i=3;i<=n;i++) {
        int cnt=p[i-1]-1;
        if (cnt<0) cnt=(cnt+base*base)%base;
        for (int j=1;j<=a[i];j++) {
            cnt=cnt-f[i-1][j];
            if (cnt<0) cnt=(cnt+base*base)%base;
        }
        res=(res+cnt)%base;
    }
    
    cout<<res;
    return 0;
}

