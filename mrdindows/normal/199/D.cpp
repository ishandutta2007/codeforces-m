#include <iostream>
#include <fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<memory.h>
#include<algorithm>
#include<string>
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt((x)*1.)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
#define fill(m,v) memset(m,v,sizeof(m))
#define random(x) (((rand()<<15)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 stupid_cmath_make_me_cry
#define tm stupid_ctime
#include<map>
#include<set>
using namespace std;
#define mod 1000000007
typedef long long LL;
    int n,k;
    bool e=false;
    bool **a;
    int **ta;
void go(int q,int h,int t)
{
    if (!e)
    {
        if (h>=n)
        {
            e=true;
            printf("YES");
            return;
        }
        else
            if (h>=0)
        if (!a[h][q] && t<=h && t<ta[h][q])
        {
            ta[h][q]=t;
            go((q+1)%2,h+k,t+1);
            go(q,h+1,t+1);
            go(q,h-1,t+1);
        }
    }
}
int main()
{ 
scanf("%d%d",&n,&k);
scanf("\n");
    a=new bool*[n];
    ta=new int*[n];
    for (int i=0;i<n;i++)
    {
        ta[i]=new int[2];
        a[i]=new bool[2];
        ta[i][1]=2000000;
        ta[i][0]=2000000;
        char c;
        scanf("%c",&c);
        if (c=='X')
            a[i][0]=true;
        else a[i][0]=false;
    }
    scanf("\n");
        for (int i=0;i<n;i++)
    {   char c;
        scanf("%c",&c);
        if (c=='X')
            a[i][1]=true;
        else a[i][1]=false;
    }
    go(0,0,0);
    if (!e) printf("NO");
    return 0;
}