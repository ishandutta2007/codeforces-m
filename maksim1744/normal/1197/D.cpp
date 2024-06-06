/*
    author:  Maksim1744
    created: 22.07.2019 17:49:42
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

const ll inf = 1e16;

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    cin >> a;
    if (m == 1) {
        for (int i = 0; i < n; ++i) {
            a[i] -= k;
        }
        ll ans = 0;
        ll now = 0;
        for (int i = 0; i < n; ++i) {
            now = max({0ll, now + a[i]});
            umax(ans, now);
        }
        cout << ans << '\n';
        return 0;
    }
    vector<ll> d(m, -inf);
    d[0] = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<ll> d1(m);
        for (int j = 1; j < m; ++j) {
            d1[j] = d[j - 1] + a[i];
        }
        d1[1] -= k;
        umax(d1[1], a[i] - k);
        d1[0] = max({0ll, d[m - 1] + a[i]});
        swap(d, d1);
        for (auto p : d) {
            umax(ans, p);
        }
        show(d);
    }
    cout << ans << '\n';
    return 0;
}