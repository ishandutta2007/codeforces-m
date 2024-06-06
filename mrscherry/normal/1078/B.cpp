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

int n;
int A[105];
int cnt[105];
int DP1[105][10005];
int DP2[105][10005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    sort(A, A + n);
    DP1[0][0] = 1;
    int T = 0;
    for (int i = 1; i < 105; i++) {
        if (cnt[i] == 0) continue;
        T++;
        for (int j = 0; j < 105; j++) {
            for (int k = 0; k < 10005; k++) {
                if (DP1[j][k] == 0) continue;
                for (int c = 0; c <= cnt[i]; c++) {
                    DP2[j + c][k + c * i] += DP1[j][k];
                    setmin(DP2[j + c][k + c * i], 2);
                }
            }
        }
        for (int j = 0; j < 105; j++) {
            for (int k = 0; k < 10005; k++) {
                DP1[j][k] = DP2[j][k];
                DP2[j][k] = 0;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < 105; i++) {
        for (int j = 1; j <= cnt[i]; j++) {
            if (DP1[j][i * j] == 2) continue;
            if (DP1[j][i * j] == 0) return 1;
            ans = max(ans, j);
            if (j == cnt[i] && T == 2) ans = n;
        }
    }
    cout << ans;
}