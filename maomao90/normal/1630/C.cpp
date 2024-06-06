// time-limit: 2000
// problem-url: https://codeforces.com/contest/1630/problem/C

// Fight the good fight of the faith. Take hold of the 
// eternal life to which you were called when you made 
// your good confession in the presence of many witnesses
// 1 Timonthy 6:12
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

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MAXN 200005

int n;
int a[MAXN];
int mn[MAXN], mx[MAXN];
int sm[MAXN];
vii rng;
int ans;

int main() {
    scanf("%d", &n);
    REP (i, 0, n + 1) {
        mn[i] = INF; mx[i] = -INF;
    }
    REP (i, 0, n) {
        scanf("%d", &a[i]);
        mnto(mn[a[i]], i);
        mxto(mx[a[i]], i);
    }
    REP (i, 1, n + 1) {
        if (mn[i] == INF || mn[i] == mx[i]) continue;
        rng.pb(MP(mn[i], mx[i]));
        sm[mn[i]]++;
        sm[mx[i] + 1]--;
        debug("%d %d\n", mn[i], mx[i]);
    }
    if (rng.empty()) {
        printf("0\n");
        return 0;
    }
    REP (i, 0, n) {
        if (i > 0) sm[i] += sm[i - 1];
        if (sm[i] > 0) {
            ans++;
        }
    }
    sort(ALL(rng));
    int r = rng[0].SE, nr = rng[0].SE, cnt = 1;
    REP (i, 1, rng.size()) {
        if (rng[i].FI < r) {
            mxto(nr, rng[i].SE);
        } else if (rng[i].FI < nr) {
            r = nr;
            mxto(nr, rng[i].SE);
            cnt++;
        } else {
            if (nr != r) {
                cnt++;
            }
            ans -= cnt + 1;
            cnt = 1;
            r = nr = rng[i].SE;
        }
    }
    if (nr != r) {
        cnt++;
    }
    ans -= cnt + 1;
    printf("%d\n", ans);
    return 0;
}