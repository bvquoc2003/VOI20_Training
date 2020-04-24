#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="LINES";
const int N=203;

int n, x[N], y[N];
int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);

    while(cin>>n) {
        if (n==0) break;
        set<pair<int,int>> mp;
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        int mx,my,m;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                my=(y[j]-y[i]);
                mx=(x[j]-x[i ]);
                m=__gcd(mx,my);
                if(m!=0){
                    my/=m;mx/=m;
                    if(mx<0) {
                        mx*=-1;
                        my*=-1;
                    }
                }
                mp.insert(make_pair(mx,my));
            }
        }
        cout<<mp.size()<<endl;
    }
    return 0;
}