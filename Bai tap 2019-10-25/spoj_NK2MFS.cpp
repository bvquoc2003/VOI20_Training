#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct data {
    int id, a, b;
    data () {id=0;a=0;b=0;}
    data (int _id, int _a, int _b) {id=_id; a=_a; b=_b;}
    bool operator < (data x) {return (a<b && (x.a>=x.b));}
};
bool cmpn1(const data &x1, const data &x2) {return x1.a<x2.a;}
bool cmpn2(const data &x1, const data &x2) {return x1.b>x2.b;}
int n, res;
vector <data> d;
vector <int> t1, t2;
int32_t main(void) {
    FastIO;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // Enter
    cin>>n; d.resize(n);
    for (int i=0;i<n;i++) {
        d[i].id=i+1;
        cin>>d[i].a;
    }
    for (int i=0;i<n;i++) cin>>d[i].b;
    // Johnson
    sort(d.begin(),d.end());
    int pos=0;
    while (d[pos].a<d[pos].b && pos<n-1) pos++;
    sort(d.begin(),d.begin()+pos,cmpn1);
    sort(d.begin()+pos,d.end(),cmpn2);
    // Solve
    t1.resize(n+1); t2.resize(n+1);
    for (int i=1;i<=n;i++) {
        t1[i]=t1[i-1]+d[i-1].a;
        t2[i]=max(t1[i],t2[i-1])+d[i-1].b;
    }
    res=t2[n];
    // Print
    cout<<res<<endl;
    for (int i=0;i<n;i++) cout<<d[i].id<<" ";
    return 0;
}