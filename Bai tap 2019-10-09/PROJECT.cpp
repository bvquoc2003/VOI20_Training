#include <bits/stdc++.h>
using namespace std;
const int MaxN = 4e5+5;
int64_t h, s, d, res;
int n, t;
vector <int> a, b, amax;
void Nhap() {
    freopen("project.inp","r",stdin);
    cin>>n>>h>>s>>d;
    a.resize(n+2);
    b.resize(n);
    amax.resize(n+2);
    for (int i=1;i<=n;++i) cin>>a[i];
    t=(h+d)/s+1;
}

void Init() {
    deque<int> q;
    for (int i=n; i>0;i--) {
        while (!q.empty() && a[q.back()] <= a[i]) q.pop_back();
        q.push_back(i);
        if (q.front()-i>=t) q.pop_front();
        amax[i]=a[q.front()];
    }
}

void Solve() {
    b[0]=a[1];
    res=h*b[0] + s*b[0];
    for (int i=2;i<=n;++i) {
        b[i-1]= ((b[i-2]<=a[i]) ? a[i] : min(b[i-2], amax[i]));
        if (b[i-1]>b[i-2]) res+=h*(b[i-1]-b[i-2]);
        else res+=d*(b[i-2]-b[i-1]);
        res+=b[i-1]*s;
    }
    res+=b[n-1]*d;
}

void Xuat() {
    freopen("project.out","w",stdout);
    cout<<res<<endl;
    for (int x:b) cout<<x<<" ";
}

int32_t main(void) {
    Nhap();
    Init();
    Solve();
    Xuat();
}
