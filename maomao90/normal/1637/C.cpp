// time-limit: 1000
// problem-url: https://codeforces.com/contest/1637/problem/C

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 200005

int t;
int n;
int a[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 0, n) {
            cin >> a[i];
        }
        if (n == 3) {
            if (a[1] % 2 == 0) {
                cout << a[1] / 2 << '\n';
            } else {
                cout << "-1\n";
            }
            continue;
        }
        bool pos = 0;
        REP (i, 1, n - 1) {
            if (a[i] != 1) {
                pos = 1;
                break;
            }
        }
        if (!pos) {
            cout << "-1\n";
            continue;
        }
        ll ans = 0;
        REP (i, 1, n - 1) {
            ans += (a[i] + 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}