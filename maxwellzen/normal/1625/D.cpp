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

int n, k;

pi maxor(vi a, vi b, int bit) {
    if (a.size()==1 && b.size()==1) return mp(a[0], b[0]);
    vi azero, aone, bzero, bone;
    for (int i : a) if (i & 1<<bit) aone.pb(i); else azero.pb(i);
    for (int i : b) if (i & 1<<bit) bone.pb(i); else bzero.pb(i);
    pi ans = mp(0, 0);
    if (!azero.empty() && !bone.empty()) {
        pi res = maxor(azero, bone, bit-1);
        if ((res.F^res.S) > (ans.F^ans.S)) ans = res;
    }
    if (!aone.empty() && !bzero.empty()) {
        pi res = maxor(aone, bzero, bit-1);
        if ((res.F^res.S) > (ans.F^ans.S)) ans = res;
    }
    if (ans != mp(0, 0)) return ans;
    if (!aone.empty() && !bone.empty()) {
        pi res = maxor(aone, bone, bit-1);
        if ((res.F^res.S) > (ans.F^ans.S)) ans = res;
    }
    if (!azero.empty() && !bzero.empty()) {
        pi res = maxor(azero, bzero, bit-1);
        if ((res.F^res.S) > (ans.F^ans.S)) ans = res;
    }
    return ans;
}
vi maxset(vi a, int bit) {
    if (a.size()<=1) return a;
    vi ans;
    vi zero, one;
    for (int i : a) if (i & 1<<bit) one.pb(i); else zero.pb(i);
    if (k & 1<<bit) {
        if (one.empty() || zero.empty()) {
            ans.pb(a[0]);
            return ans;
        }
        pi res = maxor(zero, one, bit-1);
        if ((res.F^res.S) >= k) ans.pb(res.F), ans.pb(res.S);
        else ans.pb(a[0]);
        return ans;
    } else {
        if (!zero.empty()) {
            vi res = maxset(zero, bit-1);
            ans.insert(ans.end(), all(res));
        }
        if (!one.empty()) {
            vi res = maxset(one, bit-1);
            ans.insert(ans.end(), all(res));
        }
        return ans;
    }
}

void solve() {
    cin >> n >> k;
    vi a;
    read(a, n);
    if (k==0) {
        cout << n << nl;
        FOR(i, 1, n+1) cout << i << ' ';
        cout << nl;
        return;
    }
    map<int, int> loc;
    F0R(i, n) loc[a[i]] = i;
    vi b(all(a)); sort(all(b)); b.rsz(unique(all(b))-b.begin());
    vi res = maxset(b, 30);
    if (res.size()<2) cout << -1 << nl;
    else {
        cout << res.size() << nl;
        for (int i : res) cout << loc[i]+1 << ' ';
        cout << nl;
    }
}

int main() {
    setIO();
    cout << fixed << setprecision(15);
    int t = 1;
    
    while (t--) {
        solve();
    }
}