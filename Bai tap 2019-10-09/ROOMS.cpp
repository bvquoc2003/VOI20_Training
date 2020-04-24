#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MaxN = 1e5 + 1;

struct TPoint {
    int x;
    int kind;
    int Conference;
    TPoint() {x=INT_MAX; kind=-1; Conference=-1; }
};

TPoint p[2*MaxN];
int Room[MaxN]; 
int n;
stack<int> s;

typedef vector<int> TRoom;

TRoom r[MaxN]; 

void Enter() {
    freopen("ROOMS.INP","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int s, f;
        cin>>s>>f;
        p[i].x=s; p[i].kind=1; p[i].Conference=i;
        p[i+n].x=f; p[i+n].kind=0; p[i+n].Conference=i;
    }
}

bool cmp(const TPoint &p, const TPoint &q) {return p.x < q.x || (p.x == q.x && p.kind < q.kind);}

void Process() {
    sort(p+1, p+2*n+1, cmp);
    int res = 0;
    int Cnt = 0;
    for (int i=n;i>=1;i--) s.push(i);
    for (int i=1;i<=2*n;i++)
        if (p[i].kind == 1) {
            int a=p[i].Conference;
            int b=s.top();
            Room[a]=b; r[b].push_back(a);
            s.pop();
            Cnt++;
            if (res<Cnt) res=Cnt;
        } else {
            s.push(Room[p[i].Conference]);
            Cnt--;
        }
    freopen("ROOMS.OUT","w",stdout);
    cout<<res<<'\n';
    for (int i=1;i<=res;i++) {
        for (int j=0;j<r[i].size();j++) cout<<r[i][j]<<" ";
        cout<<'\n';
    }
}

int32_t main() {
    FastIO;
    Enter();
    Process();
}

