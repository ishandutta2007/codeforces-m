//MatrixCascade

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
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
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
int T;

int a[201001];
char c[101010];
int b[200];
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		b[1]=1;
		up(i,2,n)b[i]=b[i-1]+n;
		int bas=0;
		if(n!=2)
		{
			up(i,1,n)
			{
				up(j,i,n)
				{
					printf("%lld ",b[j]+bas);
				}
				up(j,1,i-1)
				{
					printf("%lld ",b[j]+bas);
				}
				puts("");	++bas;
			}
		
		}
		else
		{
			puts("-1");
		}
	} 
}