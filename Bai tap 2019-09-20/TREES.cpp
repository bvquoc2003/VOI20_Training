#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef pair<long long,int> ii;
int res=-1, max_cs=0, n;
vector <ii> a;
int32_t main(void) {
    FastIO;
    freopen("TREES.INP","r",stdin);
    freopen("TREES.OUT","w",stdout);
    cin>>n; a.resize(n);
    for (int i=0;i<n;i++) {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a.begin(),a.end());
    for (int i=n-1;i>=0;i--) {
        res=max(res,max_cs-a[i].second);
        max_cs=max(max_cs,a[i].second);
    }
    cout<<res;
    return 0;
}