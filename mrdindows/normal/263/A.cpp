#include <iostream>
#include <fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<vector>
#include<ctime>
#include<memory.h>
#include<algorithm>
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt((x)*1.)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))  
#define abs(x) ((x)>0?(x):-(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define CL(x) memset(x, 0, sizeof(x))
#define SINF(x) memset(x, 0x3F, sizeof(x));
#define SVAL(x, y) memset(x, y, sizeof(x))
#define CP(t, f) memcpy(t, f, sizeof(f));
#define CPS(t, f, s) memcpy(t, f, s*sizeof(f[0]));
#define random(x) (((rand()*25)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 qstupid_cmath_make_me_cry
#define tm stupid_ctime
#define pb push_back
#define mp make_pair
#include<map>
#include<set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#pragma comment(linker,"/STACK:256000000")
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<int, bool> pib;

#define maxll 0x7fffffffffffffffLL
#define mod 1000000007
#define INF 1000000000
int main()
{
    int a[5][5];
    int i,j;
    int res=0;
    for (i=0;i<5;i++)
    {
        for (j=0;j<5;j++)
        {
            int x;
            cin>>x;
            if (x==1)
            {
                res=abs(2-i)+abs(2-j);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}