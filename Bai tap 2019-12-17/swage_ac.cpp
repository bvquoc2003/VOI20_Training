#include <bits/stdc++.h>
#define pii pair<int, int>
#define fr(i, x, y) for(int i = x; i<=y; i++)
#define fi first
#define se second
using namespace std;
pii pois[2010];
int N;
double slopes[2010];
void inp(){
    freopen("swage.inp", "r", stdin);
    freopen("swage.out", "w", stdout);
    scanf("%d", &N);
    fr(i, 1, N)scanf("%d%d", &pois[i].fi, &pois[i].se);
}
double fslope(pii A, pii B){
    if(A.fi == B.fi) return 1e18;
    else return (double)(B.second - A.se)/(B.fi - A.fi);
}
void procs(){
    int res = 0;
    fr(i, 1, N-1){
        //map<double, int> mp;
        fr(j, i+1, N){
            slopes[j] = fslope(pois[i], pois[j]);
            //mp[slopes[j]]++;
            //res = max(res, mp[slopes[j]]);
        }
        sort(slopes+i+1, slopes+N+1);
        int cnt = 2;
        fr(j, i+2, N){
            if(slopes[j]!=slopes[j-1]){
                res = max(res, cnt);
                cnt = 1;
            }
            cnt++;
        }
        res = max (res, cnt);
    }
    cout<<res<<endl;
}
int main(){
    inp();
    procs();
    return 0;
}
/*
12
0 0
0 1
0 2
1 1
2 0
2 1
2 2
4 2
3 3
4 4
6 3
5 5

*/
