#include <bits/stdc++.h>
#define ft(i,x,y) for(int i=x;i<=y;i++)
#define ftd(i,x,y) for(int i=x;i>=y;i--)
#define ftm(i,x,y) for(int i=x;i<y;i++)
#define ftdm(i,x,y) for(int i=x;i>y;i--)
#define fi first
#define se second
#define add push_back
#define ad push
using namespace std;
typedef struct pair <long long,long long> ii;
void io()
{
    
}
bool cw(ii a,ii b,ii c)
{
	return a.fi*(b.se-c.se)+b.fi*(c.se-a.se)+c.fi*(a.se-b.se)<0;
}
bool ccw(ii a,ii b,ii c)
{
	return a.fi*(b.se-c.se)+b.fi*(c.se-a.se)+c.fi*(a.se-b.se)>0;
}
long long _fabs(long long a)
{
	if(a<0) return -a;
	return a;
}
long long _S(ii a,ii b,ii c)
{
	return _fabs(a.fi*b.se-a.se*b.fi+b.fi*c.se-b.se*c.fi+c.fi*a.se-c.se*a.fi);
}
int n;
ii a[3001];
vector <ii> up,down,conver;
void conver_hull()
{
	ii p1=a[1],p2=a[n];
	up.add(a[1]);
	down.add(a[1]);
	ft(i,2,n)
	{
		if(i==n or cw(p1,a[i],p2))
		{
			while(up.size()>=2 and !cw(up[up.size()-2],up[up.size()-1],a[i])) up.pop_back();
			up.add(a[i]);
		}
		if(i==n or ccw(p1,a[i],p2))
		{
			while(down.size()>=2 and !ccw(down[down.size()-2],down[down.size()-1],a[i])) down.pop_back();
			down.add(a[i]);
		}
	}
	ftm(i,0,up.size()) conver.add(up[i]);
	ftd(i,down.size()-2,1) conver.add(down[i]);
	//cout<<"\n";
	//ftm(i,0,conver.size()) cout<<conver[i].fi<<" "<<conver[i].se<<"\n";
}
long long S()
{
	long long _s=0;
	ftm(i,0,conver.size())
	{
		if(i+2>=conver.size()) continue;
		int z=i+2;
		ii u=conver[i];
		long long __s=0;
		ftm(j,i+1,conver.size())
		{
			ii v=conver[j];
			__s=_S(u,conver[j],conver[z]);
			while(z+1<conver.size() and _S(u,v,conver[z+1])>=__s)
			{
				__s=_S(u,v,conver[z+1]);
				z++;
			}
			_s=max(_s,__s);
			
		}
	}
	return _s;
}
int main()
{
    freopen("TRILAND.inp","r",stdin);
    freopen("TRILAND.out","w",stdout);
    scanf("%d",&n);
    ft(i,1,n)
    	scanf("%lld%lld",&a[i].fi,&a[i].se);
    sort(a+1,a+n+1);
    conver_hull();
    long long ans=S();
    //cout<<ans<<" ";
    if(ans%2==0) cout<<ans/2<<"."<<0;
    else cout<<ans/2<<"."<<5;
    return 0;
}


