#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;

int can(int *B)
{
    int A[3]={B[0], B[1], B[2]};
    int sum = 0;
    rep(i,0,3)
        sum += A[i];
    bool ok = 1;
    rep(i,0,3)
        if (A[i] >= sum - A[i])
            ok = 0;
    int res = ok;
    ok = 1;
    rep(i,0,3)
        if (A[i] > sum - A[i])
            ok = 0;
    res += ok;
    return res;
}

void run()
{
    int A[4];
    rep(i,0,4)
    {
        scanf("%d",A+i);
    }
    int mx = 0;
    rep(i,0,4)
    {
        swap(A[i], A[3]);
        mx = max(mx, can(A));
        swap(A[i], A[3]);
    }
    if (mx == 0)
        puts("IMPOSSIBLE");
    else if (mx == 1)
        puts("SEGMENT");
    else
        puts("TRIANGLE");
    
}


//#define prob "path"


int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}