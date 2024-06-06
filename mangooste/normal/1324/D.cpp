#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstring>
#include <iomanip>

using ll = long long;
using namespace std;

//#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    vector<int> s(n);
    forn(i, n) s[i] = a[i] - b[i];
    sort(all(s));
    ll ans = 0;
    forn(i, n) {
        ans += s.end() - upper_bound(all(s), -s[i]);
        ans -= s[i] > 0;
    }
    ans >>= 1;
    cout << ans << '\n';
}