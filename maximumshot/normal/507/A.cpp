// by maximumSHOT
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>
#include <stdio.h>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    int n, k;

    cin >> n >> k;

    vec<pii> a(n);

    for(int i(0);i < n;i++) cin >> a[i].first, a[i].second = i + 1;

    sort(ALL(a));

    int s = 0, q = 0;

    vec<int> ans;

    q = n;

    for(int i(0);i < n;i++)
    {
        s += a[i].first;
        if(s > k) 
        {
            q = i;
            break;
        }
    }

    cout << q << '\n';

    for(int i(0);i < q;i++) cout << a[i].second << ' ';

    return true;
}

int main()
{
    //while(solve());
    solve();
 
    return 0;
}