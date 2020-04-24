#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const string INP=".INP", OUT=".OUT";
const string FILENAME="ROBOT";
const int N=1000006;

int n, cnt_l=0, cnt_r=0;
int x[N], y[N];

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) 
        cin>>x[i]>>y[i];

    for (int i=3;i<=n;i++) {

        if(x[i]-x[i-2]==1 && y[i]-y[i-2]==1)
            (x[i-1]==x[i])?(cnt_l++):(cnt_r++);

        if(x[i]-x[i-2]==-1 && y[i]-y[i-2]==1)
            (y[i-1]==y[i])?(cnt_l++):(cnt_r++);

        if(x[i]-x[i-2]==-1 && y[i]-y[i-2]==-1)
            (x[i-1]==x[i])?(cnt_l++):(cnt_r++);

        if(x[i]-x[i-2]==1 && y[i]-y[i-2]==-1)
            (y[i-1]==y[i])?(cnt_l++):(cnt_r++);
    }

    cout<<cnt_r<<' '<<cnt_l;
    return 0;
}
