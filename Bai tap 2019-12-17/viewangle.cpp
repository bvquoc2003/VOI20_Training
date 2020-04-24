#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i= a; i<= b; i++)
#define FORD(i,a,b) for(int i= a; i>= b; i--)
#define For(i,a,b) for(int i= a; i< b; i++)
#define Ford(i,a,b) for(int i= a; i> b; i--)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define Fill(s,a) memset(s,a,sizeof(s));
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const int N = 100100;

int n, x[N], y[N];
double g[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cout <<M_PI;
    //freopen("viewangle.inp","r",stdin);
    //freopen("viewangle.out","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> x[i] >> y[i];
    FOR(i,1,n)
    {
        g[i] = atan2(y[i],x[i]);
        if (g[i] < 0) g[i] += 2 * M_PI;
    }
    sort(g+1,g+1+n);
    double t = (g[n] - g[1])/M_PI * 180.0;
    FOR(i,2,n) t = min(t,360.0 - (g[i] - g[i-1])/M_PI * 180.0);

    printf("%.6lf",t);
    return 0;
}
