//This code is made by Yiran Empty.
//GrandMaster When??

#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
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
int a[101001];
signed main()
{
	int T=1;
	while(T--)
	{
		n=read();
		up(i,1,n)a[i]=read();
		m=read();
		int lst=0;
		up(i,1,m)
		{
			int opt=read(),l=(read()+lst-1)%n+1,r=(read()+lst-1)%n+1;
			if(l>r)l^=r^=l^=r;
			if(opt==2)
			{
				k=(read()+lst-1)%n+1;
				int ans=0;
				for(;l<=r;++l)ans+=a[l]==k;
				printf("%d\n",lst=ans);
			}
			else
			{
				int nw=a[r];
				for(;r>l;--r)a[r]=a[r-1];
				a[l]=nw;
			}
		}
	}
}
/*
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/