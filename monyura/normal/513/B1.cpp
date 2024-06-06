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
#include <cassert>


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

void run()
{
    int n, m;
    cin>>n>>m;
    int P[9] = {1,2,3,4,5,6,7,8,9};
    int sum[100100] = {0};
    int pos = 0;
    do
    {
        rep(i,0,n)
        rep(j,i,n)
        {
            int mn = 100;
            rep(k,i,j+1)
            mn = std::min(mn, P[k]);
            sum[pos] += mn;
        }
        ++pos;
    }
    while (next_permutation(P,P+n));
    sort(P,P+n);
    int mx = *max_element(sum, sum+100100);
    rep(i,0,100100)
    {
        if (sum[i] == mx)
            --m;
        if (m==0)
        {
            rep(i,0,n)
            printf("%d ", P[i]);
            puts("");
            return;
        }
        next_permutation(P, P+n);
    }
}

int main()
{
#ifdef _MONYURA_
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
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