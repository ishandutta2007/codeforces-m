#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const ll INFLL = 1e18;
const int MAXN = 1e6 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);in(a);in(b);
    swap(a, b);
    ll initial = 0;
    for (int i = 0; i < n; i++)
        initial += a[i] * b[i];
    ll ans = 0;
    vector<ll> pref_in(n + 1);
    for (int i = 1; i <= n; i++)
        pref_in[i] = pref_in[i - 1] + a[i - 1] * b[i - 1];
    for (int beg = n; beg >= 1; beg--) {
        vector<ll> pref(n + 1);
        for (int i = 1; i <= beg; i++)
            pref[i] = pref[i - 1] + a[i - 1] * b[1 + beg - i - 1];
        for (int i = 1; i <= beg; i++) {
            int ind = 1 + beg - i;
            if (ind < i)
                break;
            ans = min(ans, -(pref[ind] - pref[i - 1] - (pref_in[ind] - pref_in[i - 1])));
        }
    }
    for (int beg = n; beg >= 1; beg--) {
        vector<ll> pref(n + 1);
        for (int i = beg; i <= n; i++)
            pref[i] = pref[i - 1] + a[i - 1] * b[n + beg - i - 1];
//        cout << beg << '\n';
//        for (auto to:pref)
//            cout << to << " ";
//        cout << '\n';
        for (int i = beg; i <= n; i++) {
            int ind = n + beg - i;
            if (ind < i)
                break;
            ans = min(ans, -(pref[ind] - pref[i - 1] - (pref_in[ind] - pref_in[i - 1])));
        }
    }
    cout << initial - ans << '\n';
}

int main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
//    cin>>_t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}