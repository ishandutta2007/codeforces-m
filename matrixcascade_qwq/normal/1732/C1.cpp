/*
	Author : SyadouHayami & Silviasylvia
*/


//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
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
#define edge1 int head[maxn],to[maxn<<1],nxt[maxn<<1],tot;\
void add(int a,int b)\
{\
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;\
}
#define edge2 int head[maxn],to[maxn<<1],nxt[maxn<<1],tot,w[maxn<<1];\
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
/*
#define ls ((x<<1))
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
void pushup(int x)
{
	//do sth
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		//do sth
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		//do sth
		return;
	}
	if(ql<=mid)update(ls,l,mid,ql,qr);
	if(mid<qr)update(rs,mid+1,r,ql,qr);
	pushup(x);
}
void query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		//do sth
		return;
	}
	if(ql<=mid)
	{
		query(ls,l,mid,ql,qr);
	}
	if(mid<qr)
	{
		query(rs,mid+1,r,ql,qr);
	}
	return;
}
*/
const int maxn=1e5+10;
int f[31][maxn];
int a[maxn];
int p[31][maxn],q[31][maxn];
int c[31],d[31];
signed main()
{
	int T=read();
	while(T--)
	{
		int qqq;rdn;rd(qqq);
		upn rd(a[i]);
		upn
		{
			up(j,0,29)
			{
				if((a[i]>>j)&1)
				{
					f[j][i]=f[j][i-1]+1;
					p[j][i]=i;
				}
				else f[j][i]=f[j][i-1],p[j][i]=p[j][i-1]; 
			}
		}
		up(j,0,29)q[j][n+1]=n+1;
		pu(i,n,1)
		{
			up(j,0,29)
			{
				if((a[i]>>j)&1)
				{
					q[j][i]=i;
				}
				else q[j][i]=q[j][i+1]; 
			}
		}
		while(qqq--)
		{
			int l,r;rd(l);rd(r);
			vector<pii>v;
			int qwq=30;
			int nl=n+1,nr=0;
			up(j,0,29)
			{
				int vl=f[j][r]-f[j][l-1];
				if(vl<=1)
				{
					--qwq;continue;
				}
				if(vl%2==0)
				{
					chkmin(nl,q[j][l]);chkmax(nr,p[j][r]);--qwq;
				}
				else
				{
//					cout<<j;edl;
					chkmin(nl,q[j][q[j][l]+1]);chkmax(nr,p[j][p[j][r]-1]);
					v.ep(mkp(q[j][l],-j-1));v.ep(mkp(p[j][r],j+1));
					c[j+1]=q[j][l];d[j+1]=p[j][r];
				}
			}
//			cout<<qwq;edl;
			sort(v.begin(),v.end());
			int ql=n+1,qr=0;
			int ans=n+1;
			if(qwq==0)
			{
				if(nl>nr)nl=nr=l;
				opls(nl);opls(nr);edl;continue;
			}
			multiset<int>qw;
			fp v pf
			{
				int i=to.fi,j=to.se;
//				cout<<i<<" "<<j;edl;
				if(j<0)
				{
					qw.insert(i);
				}
				else
				{
//					cout<<j;edl;
					qw.erase(qw.find(c[j]));qw.insert(i);
				}
//				cout<<*qw.begin();edl;
				if(qw.size()==qwq)
				{
					int L=min(nl,*qw.begin());
					int R=max(nr,*qw.rbegin());
//					cout<<nr;edl;
					if(R-L+1<ans)
					{
						ans=R-L+1;ql=L;qr=R;
					}
				}
			}
			opls(ql);opls(qr);edl;
			
		}
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/