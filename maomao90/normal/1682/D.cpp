// time-limit: 1000
// problem-url: https://codeforces.com/contest/1682/problem/D

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
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 200005;

int t;
int n;
string s;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int ones = 0;
        REP (i, 0, n) {
            ones += s[i] == '1';
        }
        if (ones == 0 || ones % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        vii ans;
        vi vo;
        REP (i, 0, n) {
            if (s[i] == '0') {
                if (i == 0) {
                    ans.pb({n - 1, i});
                } else {
                    ans.pb({i, i - 1});
                }
            } else {
                if (i == 0) {
                    vo.pb(n - 1);
                } else {
                    vo.pb(i - 1);
                }
            }
        }
        REP (i, 1, vo.size()) {
            ans.pb({vo[0], vo[i]});
        }
        cout << "YES\n";
        for (auto [a, b] : ans) {
            cout << a + 1 << ' ' << b + 1 << '\n';
        }
    }
    return 0;
}