//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ft(x) for(int i=head[x];i;i=nxt[i])
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fp for(auto to:
#define pf )
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define mkp make_pair
#define fi first
#define se second
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
#define pb push_back
#define edge1 int head[maxn],to[maxn],nxt[maxn],tot;\
void add(int a,int b)\
{\
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;\
}
#define edge2 int head[maxn],to[maxn],nxt[maxn],tot,w[maxn];\
void add(int a,int b,int c)\
{\
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;w[tot]=c;\
}
#define Mod998 const int mod=998244353;\
int qpow(int a,int b=mod-2)\
{\
	int ans=1;\
	while(b)\
	{\
		if(b&1)ans=1ll*ans*a%mod;\
		a=1ll*a*a%mod;\
		b>>=1;\
	}\
	return ans;\
}\
void Add(int &a,int b)\
{\
	a+=b;if(a>=mod)a-=mod;\
}\
void Sub(int &a,int b)\
{\
	a-=b;if(a<0)a+=mod;\
}\
int Mul(int a,int b)\
{\
	return 1ll*a*b%mod;\
}\
int Frac(int a,int b)\
{\
	return 1ll*a*qpow(b)%mod;\
}

#define Mod1e9 const int mod=1e9+7;\
int qpow(int a,int b=mod-2)\
{\
	int ans=1;\
	while(b)\
	{\
		if(b&1)ans=1ll*ans*a%mod;\
		a=1ll*a*a%mod;\
		b>>=1;\
	}\
	return ans;\
}\
void Add(int &a,int b)\
{\
	a+=b;if(a>=mod)a-=mod;\
}\
void Sub(int &a,int b)\
{\
	a-=b;if(a<0)a+=mod;\
}\
int Mul(int a,int b)\
{\
	return 1ll*a*b%mod;\
}\
int Frac(int a,int b)\
{\
	return 1ll*a*qpow(b)%mod;\
}

#define DSU int fa[maxn];\
int find(int x)\
{\
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);\
}\
void merge(int x,int y)\
{\
    int fx=find(x),fy=find(y);\
    if(fx==fy)return;\
    fa[fx]=fy;\
}\
void S(int x)\
{\
    up(i,1,x)fa[i]=i;\
}
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
void print(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}


#define inf 1000000000000000000ll
ll Max(ll a=-inf,ll b=-inf,ll c=-inf,ll d=-inf,ll e=-inf,ll f=-inf,ll g=-inf,ll h=-inf)
{
	return max(max(max(a,b),max(c,d)),max(max(e,f),max(g,h)));
}
ll Min(ll a=inf,ll b=inf,ll c=inf,ll d=inf,ll e=inf,ll f=inf,ll g=inf,ll h=inf)
{
	return min(min(min(a,b),min(c,d)),min(min(e,f),min(g,h)));
}
#undef inf
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
const int maxn=808080;

int ans[maxn],tag[maxn],as[maxn];
#define ls ((x<<1))
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
void pushup(int x)
{
	//do sth
	ans[x]=max(ans[ls],ans[rs]);as[x]=min(as[ls],as[rs]);
}
void pushdown(int x)
{
	if(!tag[x])return;
	ans[ls]+=tag[x];ans[rs]+=tag[x];
	tag[ls]+=tag[x];tag[rs]+=tag[x];
	as[ls]+=tag[x];as[rs]+=tag[x];
	tag[x]=0;
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		ans[x]=as[x]=-1*l;tag[x]=0;
	//	cout<<as[x];edl;
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr)
	{
		ans[x]+=v;tag[x]+=v;as[x]+=v;
		//do sth
		return;
	}
	pushdown(x);
	if(ql<=mid)update(ls,l,mid,ql,qr,v);
	if(mid<qr)update(rs,mid+1,r,ql,qr,v);
	pushup(x);
}
void upd(int x,int l,int r,int p,int v)
{
	if(l==r)
	{
		as[x]=v;ans[x]=v;tag[x]=0;return;
	}
	pushdown(x);
	if(p<=mid)upd(ls,l,mid,p,v);
	else upd(rs,mid+1,r,p,v);
	pushup(x);
}
int query1(int x,int l,int r,int ql,int qr)
{
	int ass=Max();
	if(ql<=l&&r<=qr)
	{
		return ans[x];
		//do sth
	}
	pushdown(x);
	if(ql<=mid)
	{
		chkmax(ass,query1(ls,l,mid,ql,qr));
	}
	if(mid<qr)
	{
		chkmax(ass,query1(rs,mid+1,r,ql,qr));
	}
	return ass;
}
int query2(int x,int l,int r,int ql,int qr)
{
	int ans=Min();
	if(ql<=l&&r<=qr)
	{
		return as[x];
		//do sth
	}
	pushdown(x);
	if(ql<=mid)
	{
		chkmin(ans,query2(ls,l,mid,ql,qr));
	}
	if(mid<qr)
	{
		chkmin(ans,query2(rs,mid+1,r,ql,qr));
	}
	return ans;
}
vector<int>v[202020];
int a[202020];
int anss[202020];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		upn rd(a[i]),v[a[i]].ep(i);
		build(1,0,n);
		pu(i,n,1)
		{
			fp v[i] pf
			{
				update(1,0,n,to,n,2);
			}
			fp v[i] pf
			{
				
				int nw=query1(1,0,n,to,n)-query2(1,0,n,0,to-1);chkmax(anss[to],nw/2);
			}
		}memset(tag,0,sizeof(tag));
		build(1,0,n);
		upn
		{
			fp v[i] pf
			{
				update(1,0,n,to,n,2);
			}
			fp v[i] pf
			{
			//	if(to==n)cout<<query1(1,0,n,to,n)<<" "<<query2(1,0,n,0,to-1),edl;
				int nw=query1(1,0,n,to,n)-query2(1,0,n,0,to-1);chkmax(anss[to],(nw-1)/2);
			}
		}
		upn opls(anss[i]);edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/