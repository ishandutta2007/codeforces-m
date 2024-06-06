#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> iset;

typedef long long ll;
typedef long double db;
typedef string str;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<str> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define arr array
#define nl '\n'
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"

#ifndef LOCAL
#define debug(...) 0
#else
#include "/Users/maxwellzen/CP/debug.cpp"
#endif

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<int N> using ai = array<int, N>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void read(vector<T>& a, int n) {a.rsz(n); F0R(i, n) cin >> a[i];}
template<class T> void read(vector<vector<T>>& a, int n, int m) {a.assign(n, vector<T>(m)); F0R(i, n) F0R(j, m) cin >> a[i][j];}
template<class T> void print(vector<T>& a, int n) {F0R(i, n) cout << a[i] << ' '; cout << nl;}
template<class T> void print(vector<vector<T>>& a, int n, int m) {F0R(i, n) {F0R(j, m) cout << a[i][j] << ' '; cout << nl;}}
template<class T> bool btw(T x, T a, T b) {return a <= x && x <= b;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 1e9+7;// 998244353;
ll gcd(ll a, ll b){return b == 0 ? a: gcd(b, a%b);}
const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}; // D R U L

void setIO(string name="") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name != "") {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = -1e9; T comb(T a, T b) { return max(a,b); }
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {  // min on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

int n, u, v, tim, ans;
vvi adj;
vi dep, st, ed, cnt;
Seg<int> seg, tmp1, tmp2;

void dfs(int i, int p, int d) {
    dep[i] = d;
    st[i] = tim++;
    cnt[i] = 1;
    for (int nb : adj[i]) if (nb != p) {
        dfs(nb, i, d+1);
        cnt[i] += cnt[nb];
    }
    ed[i] = tim-1;
}
void calc(int i, int p, int x) {
    if (x < dep[i]) {
        int cur = 0;
        ckmax(cur, seg.query(st[i], ed[i]) + x - dep[i]);
        int j = (x + dep[i])/2 + 1;
        ckmax(cur, tmp1.query(0, j-1));
        ckmax(cur, tmp2.query(j, dep[i]-1) + dep[i]);
        ckmin(ans, cur);
    }
    for (int nb : adj[i]) if (nb != p) {
        int mx = max(seg.query(st[i], st[nb]-1), ed[nb]==ed[i] ? 0 : seg.query(ed[nb]+1, ed[i]));
        tmp1.upd(dep[i], mx);
        tmp2.upd(dep[i], mx + x - 2*dep[i]);
        calc(nb, i, x);
    }
}

void solve() {
    cin >> n;
    adj.clear(); adj.rsz(n);
    F0R(i, n-1) {
        cin >> u >> v; u--; v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    tim = 0;
    dep.rsz(n); st.rsz(n); ed.rsz(n); cnt.rsz(n);
    dfs(0, 0, 0);
    seg.init(n);
    F0R(i, n) seg.upd(st[i], dep[i]);
    tmp1.init(n); tmp2.init(n);
    FOR(x, 1, n+1) {
        ans = seg.query(0, n-1);
        calc(0, 0, x);
        cout << ans << ' ';
    }
    cout << nl;
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}