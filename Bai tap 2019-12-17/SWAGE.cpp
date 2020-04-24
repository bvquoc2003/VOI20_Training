#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define x first
#define y second

const string INP=".INP", OUT=".OUT";
const string FILENAME="SWAGE";
const int INF=INT_MAX;
const int N=2003;

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

int n; ii a[N];
map <double,int> slopes;
int res=0;

int32_t main() {
	FastIO;
	freopen((FILENAME+INP).c_str(),"r",stdin);
	freopen((FILENAME+OUT).c_str(),"w",stdout);
	Read(n);
	for (int i=1;i<=n;i++) {
		Read(a[i].x);
		Read(a[i].y);
	}

	for (int i=1;i<n;i++) {
		slopes.clear();
		for (int j=i+1;j<=n;j++) {
			double u=a[j].x-a[i].x, v=a[j].y-a[i].y;
			if (v!=0.0)
				slopes[u/v]++;
			else slopes[INF]++;
		}
		for (auto it:slopes) 
			res=max(res,it.y+1);
	}
	Write(res);
	return 0;
}