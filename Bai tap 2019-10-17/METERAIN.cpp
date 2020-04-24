#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;
void operator -= (ii& A, ii B) {A.X -= B.X; A.Y -= B.Y;}
bool CCW(ii &A, ii B, ii C) {C -= B; B -= A; return (int64_t)B.X * C.Y >= (int64_t)B.Y * C.X;}
int n, m;
vector <ii> a;
int main() {
    freopen("METERAIN.INP","r",stdin);
    freopen("METERAIN.OUT","w",stdout);
    cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin>>a[i].X>>a[i].Y;
    cin>>m;
    ii b;
    while (m--) {
        cin>>b.X>>b.Y;
        bool inside = true; a[0]=a[n];
        for(int i=1; i<=n;i++)
        if (CCW(a[i],a[i-1],b)) {
            inside=false;
            break;
        }
        cout<<(inside?"YES\n":"NO\n");
    }
    return 0;
}