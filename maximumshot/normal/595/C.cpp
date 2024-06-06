#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve()
{
    int n;

    scanf("%d", &n);

    vec< int > x(n + 1);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &x[i]);
    }

    sort(x.begin() + 1, x.end());

    int ans = inf + 10;

    for(int i = 1;i <= n / 2;i++) ans = min(ans, x[i + n / 2] - x[i]); 

    printf("%d\n", ans);

    return true;
} 

int main() {
    
    //while(solve());
    solve();    

    return 0;
}