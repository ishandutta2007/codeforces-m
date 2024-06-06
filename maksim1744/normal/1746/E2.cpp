/*
    author:  Maksim1744
    created: 15.10.2022 18:12:14
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
// #define SHOW_COLORS
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<vector<int>> dp;
    vector<vector<pair<int, int>>> fr;
    {
        const int n = 10;
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 1e9));
        fr = vector<vector<pair<int, int>>> (n + 1, vector<pair<int, int>>(n + 1, {-1, -1}));
        dp[1][1] = dp[0][1] = dp[1][0] = dp[0][0] = 0;
        dp[2][0] = dp[0][2] = 0;
        for (int k = 0; k < 100; ++k)
        for (int a = 0; a <= n; ++a) {
            for (int b = 0; a + b <= n; ++b) {
                for (int a1 = 0; a1 <= a; ++a1) {
                    for (int b1 = 0; b1 <= b; ++b1) {
                        int a2 = a - a1;
                        int b2 = b - b1;
                        int cur = max(dp[b2][a2 + b1], dp[b1][a1 + b2]) + 1;
                        if (dp[a][b] > cur) {
                            dp[a][b] = min(dp[a][b], cur);
                            fr[a][b] = {a2, b1};
                        }
                    }
                }
            }
        }
    }

    int n;
    cin >> n;

    auto ask = [&](const vector<int>& v) -> int {
        if (v.empty()) {
            return 0;
        }
        string s;
        cout << "? " << v.size() << ' ' << v << endl;
        cin >> s;
        return s == "YES";
    };

    vector<int> a, b;
    for (int i = 1; i <= n; ++i) b.pb(i);

    while (a.size() + b.size() > 2) {
        vector<int> c;
        int ca = (a.size() + 1) / 2;
        int cb = b.size() / 2;
        if (a.size() < fr.size() && b.size() < fr.size() && fr[a.size()][b.size()].first != -1 && dp[a.size()][b.size()] < 1e8) {
            tie(ca, cb) = fr[a.size()][b.size()];
        }
        for (int i = 0; i < ca; ++i) {
            c.pb(a[i]);
        }
        for (int i = 0; i < cb; ++i) {
            c.pb(b[i]);
        }
        set<int> sc(c.begin(), c.end());
        if (!ask(c)) {
            vector<int> d;
            for (int k : a) if (!sc.count(k)) d.pb(k);
            for (int k : b) if (!sc.count(k)) d.pb(k);
            sc = set<int>(d.begin(), d.end());
            swap(c, d);
        }

        vector<int> na, nb;
        for (int k : a)
            if (sc.count(k))
                nb.pb(k);
        for (int k : b)
            if (sc.count(k))
                nb.pb(k);
            else
                na.pb(k);

        swap(a, na);
        swap(b, nb);
    }

    auto check = [&](int x) {
        cout << "! " << x << endl;
        string s;
        cin >> s;
        if (s == ":)") exit(0);
    };

    for (int k : a) check(k);
    for (int k : b) check(k);

    assert(false);

    return 0;
}