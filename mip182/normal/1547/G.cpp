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

template<typename T>
vector<T> &operator--(vector<T> &v) {
    for (auto &i : v) --i;
    return v;
}

template<typename T>
vector<T> &operator++(vector<T> &v) {
    for (auto &i : v) ++i;
    return v;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i : v) os << i << ' ';
    return os;
}

template<typename T, typename U>
pair<T, U> &operator--(pair<T, U> &p) {
    --p.first;
    --p.second;
    return p;
}

template<typename T, typename U>
pair<T, U> &operator++(pair<T, U> &p) {
    ++p.first;
    ++p.second;
    return p;
}

template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
    os << p.first << ' ' << p.second;
    return os;
}

template<typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) { return mp(a.first - b.first, a.second - b.second); }

template<typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) { return mp(a.first + b.first, a.second + b.second); }

const ll INFLL = 1e18;
const int MAXN = 1e6 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

void solve() {
    int n, m;
    cin >> n >> m;
    vvi g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
    }
    vi used(n);
    vector<int> d(n);
    function<void(int)> dfs = [&](int s) {
        used[s] = 2;
        for (auto to:g[s]) {
            if (used[to] == 1)
                continue;
            if (used[to] == 2)
                d[to] = 3;
            else
                dfs(to);
        }
        used[s] = 1;
    };
    dfs(0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (d[i] == 3)
            q.push(i);
    }
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (auto to:g[f]) {
            if (d[to] == 3)
                continue;
            d[to] = 3;
            q.push(to);
        }
    }
    if (d[0] != 3) {
        set<pii, greater<pii>> ss;
        d[0] = 1;
        ss.insert({d[0], 0});
        while (!ss.empty()) {
            auto tooo = ss.begin();
            auto too = *tooo;
            ss.erase(tooo);
            int s = too.se;
            for (auto to:g[s]) {
                if (d[to] == 3)
                    continue;
                if (d[to] == 0) {
                    d[to] = d[s];
                    ss.insert({d[to], to});
                } else if (d[to] == 1) {
                    ss.erase({d[to], to});
                    d[to] = 2;
                    ss.insert({d[to], to});
                }
            }
        }
    }
    for (auto to:d)
        cout << (to <= 2 ? to : -1) << ' ';
    cout << '\n';
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
    cin >> _t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}