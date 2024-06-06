/*
    author:  Maksim1744
    created: 07.05.2021 18:09:34
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
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

void test_case(int test) {
    int n;
    cin >> n;
    show(n);
    int its = 0;
    auto ask = [&](int tp, int i, int j, int x) {
        cout << "? " << tp << ' ' << i << ' ' << j << ' ' << x << endl;
        ++its;
        assert(its <= n * 1.5 + 30);
        int ans;
        cin >> ans;
        return ans;
    };
    vector<pair<int, int>> cands;
    for (int i = 1; i + 1 <= n; i += 2) {
        if (ask(1, i, i + 1, n - 1) >= n - 1)
            cands.eb(i, i + 1);
    }
    if (n % 2 == 1)
        cands.eb(n - 1, n);

    show(cands.size(), its);

    int mx = -1;
    for (auto [a, b] : cands) {
        if (ask(1, a, b, n - 1) == n) {
            mx = b;
            break;
        }
        if (ask(1, b, a, n - 1) == n) {
            mx = a;
            break;
        }
    }
    assert(mx != -1);
    vector<int> res(n + 1);
    res[mx] = n;
    for (int i = 1; i <= n; ++i) {
        if (i != mx) {
            res[i] = ask(2, i, mx, 1);
        }
    }
    res.erase(res.begin());
    cout << "! " << res << endl;
    cerr << its << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}