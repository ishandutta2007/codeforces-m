#include <bits/stdc++.h>

#define sz(V) ((int)(V).size())
#define all(V) (V).begin(), (V).end()
#define vsort(V) sort(all(V))
#define vunique(V) (V).erase(unique(all(V)), (V).end())
#define vcomp(V) vsort(V), vunique(V)
#define fs first
#define se second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

ll gcd(ll x, ll y) { while (y) x %= y, swap(x, y); return x; }
pll operator+(pll a, pll b) { return pll(a.fs + b.fs, a.se + b.se); }
pll operator-(pll a, pll b) { return pll(a.fs - b.fs, a.se - b.se); }
ll operator*(pll a, pll b) { return a.fs * b.se - a.se * b.fs; }
template <class T> int sign(T x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }
int ccw(pll a, pll b, pll c) { return sign((b - a) * (c - b)); }
template <class T> void setmin(T &x, T y) { if (x > y) x = y; }
template <class T> void setmax(T &x, T y) { if (x < y) x = y; }
template <class T> void addval(T &x, T y) { x += y; x %= mod; }
size_t getCurrentTime() { return chrono::steady_clock::now().time_since_epoch().count(); }
struct __RandomLong__ {
    mt19937_64 rnd; __RandomLong__()
    : rnd(getCurrentTime()) {}
    ll operator()(ll Min, ll Max) { return uniform_int_distribution<ll>(Min, Max)(rnd); }
    ll operator()() { return (*this)(LONG_LONG_MIN, LONG_LONG_MAX); }
} randomLong;
struct my_hash {
    static uint64_t splitmix(uint64_t x) {
        x += 0x9e3779b97f4a7c15ull;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ull;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebull;
        return x ^ (x >> 31); }
    size_t operator()(ll x) const {
        static ll T = getCurrentTime();
        return splitmix(x + T); }
};

int n, m, k;
vector<pair<int, pii>> E;
int P[100005];
int S[100005];

int find(int x) {
    if (P[x]) return P[x] = find(P[x]);
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        S[x] = 1;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E.eb(w, pii(u, v));
    }
    vsort(E);
    for (auto i : E) {
        int w = i.fs, x, y;
        tie(x, y) = i.se;
        x = find(x);
        y = find(y);
        if (x == y) continue;
        if (S[x] < S[y]) swap(x, y);
        P[y] = x;
        S[x] += S[y];
        if (S[x] == k) {
            for (int j = 0; j < k; j++) {
                cout << w << ' ';
            }
            return 0;
        }
    }
    return 1;
}