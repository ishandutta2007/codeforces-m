#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    ll ans = 0;
    int a, num, l, r;
    cin >> a >> l >> r;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num > l && num < r) ++ans;
    }
    cout << ans;
    return 0;
}