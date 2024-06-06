#include <bits/stdc++.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool solve() {

    int n;
    cin >> n;

    vec< pii > a(n);

    for(int i = 0;i < n;i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(ALL(a));

    for(int i = 0;i < n / 2;i++)
        cout << a[i].second << ' ' << a[n - 1 - i].second << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}