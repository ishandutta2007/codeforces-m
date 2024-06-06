// time-limit: 2000
// problem-url: https://codeforces.com/contest/1693/problem/C

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
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

int n, m;
vi adj[MAXN];
int out[MAXN];
int dist[MAXN];
priority_queue<ii, vii, greater<ii>> pq;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> m;
    REP (i, 0, m) {
        int u, v; cin >> u >> v;
        adj[v].pb(u);
        out[u]++;
    }
    REP (i, 1, n + 1) {
        dist[i] = INF;
    }
    dist[n] = 0;
    pq.push({0, n});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) {
            continue;
        }
        for (int v : adj[u]) {
            if (mnto(dist[v], d + out[v])) {
                pq.push({dist[v], v});
            }
            out[v]--;
        }
    }
    cout << dist[1] << '\n';
    return 0;
}