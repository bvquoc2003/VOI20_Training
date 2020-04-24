#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define u first
#define v second

const string INP=".INP", OUT=".OUT";
const string FILENAME="DLABYR";
const int N=302, M=100005;
typedef pair<int,int> ii;

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
    x=c-'0';
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
    if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
    if (x<0) { putchar('-'); x=-x; }
    T p=1;
    for (T temp=x/10;temp>0;temp/=10) p*=10;
    for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

int n, m, k, s, t;
bool allow[N], ok;
vector <int> ke[N];
vector <bool> mark;
string ans;

void BFS(int _u, int _v) {
    queue <int> q;
    q.push(_u);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        mark[u]=true;
        for (int v:ke[u])
        if (allow[v] && !mark[v]) {
            if (v==_v) {
                ok=true;
                return;
            }
            q.push(v);
        }
    }
}

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(n); Read(m); Read(k);
    for (int i=1;i<=m;i++) {
        int u, v; 
        Read(u); Read(v);
        ke[u].push_back(v);
    }
    for (int i=1;i<=k;i++) {
        char ch; ch=getchar();
        if (ch=='Y') {
            Read(s); Read(t);
            ok=false; mark.assign(n+1,false);
            if (s==t) ok=true;
            else {
                if (allow[s] && allow[t])
                    BFS(s,t);
            }
            ans.push_back(ok?'Y':'N');
        } else {
            int j; Read(j);
            allow[j]=true;
        }
    }

    for (char ch:ans) putchar(ch);
    return 0;
}