#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MaxN=5010;
struct point { long long x, y; } s[MaxN];
int n;

bool cmp(const point &a, const point &b) { return (a.y < b.y) || ((a.y == b.y) && a.x < b.x); }
int ccw(const point &a, const point &b, const point &c) { return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y); }

bool Straight() {
    if (n<3) return true;
    for (int i = 3; i<=n; i++) {
        if (ccw(s[i-2], s[i-1], s[i]) != 0) return false;
    }
    return true;
}
int st[MaxN];
bool fr[MaxN];

void Convex_hull() {
    memset(fr, true, sizeof fr);
    int m = 0;
    for (int i = 1; i<=n; i++) {
        while (m>=2 && ccw(s[st[m-1]], s[st[m]], s[i])<0) {
            fr[st[m]]=true;
            m--;
        }
        m++;st[m] = i;fr[i] = false;
    }

    int t=m+1;
    fr[1]=true;
    for (int i=n; i>0; i--) {
        if (!fr[i]) continue;
        while (m>=t && ccw(s[st[m-1]], s[st[m]], s[i])<0) {
            fr[st[m]]=true;
            m--;
        }
        m++; st[m]=i; fr[i]=false;
    }
    int d=0;
    for (int i=1;i<=n;i++) {
        if (fr[i]) {
            s[++d]=s[i];
        }
    }
    n=d;
}

int32_t main(void) {
    FastIO;
    freopen("MILITARY.INP","r",stdin);
    freopen("MILITARY.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>s[i].x>>s[i].y;
    sort(s+1, s+n+1, cmp);
    int cnt = 0;
    while (!Straight()){
        Convex_hull();
        cnt++;
    }
    cout<<cnt;
    return 0;
}