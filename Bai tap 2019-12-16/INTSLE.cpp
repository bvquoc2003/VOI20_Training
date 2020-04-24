#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="INTSLE";

int a[3], b[3], c[3];

void Solve() {
    // cerr<<a[1]<<"*"<<b[2]<<"-"<<a[2]<<"*"<<b[1]<<endl;
    double D=a[1]*b[2]-a[2]*b[1];
    double Dx=c[1]*b[2]-c[2]*b[1];
    double Dy=a[1]*c[2]-a[2]*c[1];
    // cerr<<D<<endl;
    if (D==0) {
        if (Dx+Dy==0)
            cout<<"INFINITE\n";
        else
            cout<<"NO SOLUTION\n";
    }
    else {
        int x=Dx/D;
        int y=Dy/D;
        bool ok=true;
        for (int i=1;i<=2;i++) 
            if (a[i]*x+b[i]*y!=c[i])
                ok=false;
        if (ok) cout<<x<<' '<<y<<'\n';
        else cout<<"NO SOLUTION\n";
    }
}
int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    int T; cin>>T;
    while(T--) {
        cin>>a[1]>>b[1]>>c[1];
        cin>>a[2]>>b[2]>>c[2];
        Solve();
    }
    return 0;
}