#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define int64 long long
using namespace std;
const int MaxN=1e6;
int n, k, x, y, tmp;
vector <int> Fa(MaxN), child(MaxN);
void Join(int _x, int _y) {
    child[_x]=_y;
    Fa[_y]=_x;
}
void Shuffle() {
    Join(Fa[x], child[x]);
    Join(Fa[y], x);
    Join(x, y);
}
int32_t main() {
    FastIO;
    freopen("SHUFFLE.INP","r",stdin);
    freopen("SHUFFLE.OUT","w",stdout);
    cin>>n>>k;
    for (int i=0;i<=n;i++) Join(i,i+1);
    while (k--) {
        cin>>x>>y;
        Shuffle();
    }
    for (int i=child[0];i<=n;i=child[i]) cout<<i<<" ";
    return 0;
}