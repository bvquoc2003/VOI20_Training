#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="FOUND2";

int n, m, x;
map <int,int> cnt;

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>x;
        cnt[x]++;
    }
    while (m--) {
        cin>>x;
        cout<<cnt[x]<<endl;
    }
    return 0;
}