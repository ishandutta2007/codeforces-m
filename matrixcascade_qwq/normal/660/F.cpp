//This code is made by Yiran Empty.
//GrandMaster When??

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
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
const int maxn=202020;
int a[maxn],b[maxn],c[maxn],f[maxn],t;
int g(int x,int y)
{
	return (x*b[x]-c[x]-(y*b[y]-c[y]))/(x-y);
}
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();up(i,1,n)a[i]=read();
		up(i,1,n)b[i]=b[i-1]+a[i],c[i]=c[i-1]+a[i]*i;	int mx=0;
		up(i,1,n)
		{
			int l=0,r=t;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(g(f[mid],f[mid+1])>b[i])l=mid+1;else r=mid;
			}
			mx=max(mx,c[i]-f[l]*(b[i]-b[f[l]])-c[f[l]]);
			while(t>=1&&g(f[t-1],f[t])<g(f[t],i))t--;f[++t]=i;
		}cout<<mx;
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/