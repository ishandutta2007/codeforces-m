/*
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
FUCK YOU XJOI.
And in that light,I find deliverance.
*/

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
const int mod=1e9+7;
#define pii pair<int,int>
pii x[101010];
int y[101010];
int sum[101010],f[101010];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read(),m=read();
		up(i,1,m)
		{
			int p=read(),q=read();
			x[i]=make_pair(q,p);
			y[i]=q;
		}
		sort(x+1,x+m+1);sort(y+1,y+m+1);
		up(i,1,m)
		{
			if(!x[i].second)f[i]=1;
			int q1=lower_bound(y+1,y+m+1,x[i].second)-y,q2=lower_bound(y+1,y+m+1,x[i].first)-y;
			f[i]+=(sum[q2]-sum[q1]+mod)%mod;
			f[i]%=mod;
			sum[i+1]=(sum[i]+f[i])%mod;
			
		}
		int ans=0;
		up(i,1,m)
		{
			if(x[i].first==n)(ans+=f[i])%=mod;
		}cout<<ans;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/