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
    #define fill(m,v) memset(m,v,sizeof(m))
    //#define flush {cout.flush();fflush(stdout);}
    #define random(x) (((rand()<<15)+rand())%(x))
    #define pi 3.1415926535897932
    #define y1 stupid_cmath
    #define y0 stupid_cmath_make_me_cry
    #define tm stupid_ctime
    //#define long long long
    #include<map>
    #include<set>
    using namespace std;
    #define mod 1000000007
    typedef long long lli;
    int main()
    {  
        int n;
        cin>>n;
        for (int i=1;((i*(i+1))/2<n);i++)
        {
            int t=(i*(i+1))/2;
            int x=n-t;
            double d=sqrt(1+(long long) 8*x);
            if ((int)((1+d)/2)==(1+d)/2)
            {
                cout<<"YES";
                return 0;
            }
        }
        cout<<"NO";
        return 0;
    }