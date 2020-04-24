#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n; vector <int> a;
int k=0, cnt_neg=0, res=0;
int32_t main() {
    FastIO;
    freopen("BITSEQ.INP","r",stdin);
    freopen("BITSEQ.OUT","w",stdout);
    cin>>n; a.resize(n);
    for (int &x:a) {
        cin>>x;
        if (x==0) x=1;
        else {
            x=-1;
            cnt_neg++;
        }
    }
    for (int x:a) {
        k=max(0,k+x);
        res=max(res,k);
    }
    if (res==0) res=cnt_neg-1;
    else res=res+cnt_neg;
    cout<<res;
    return 0;
}