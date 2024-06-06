/*
    author:  Maksim1744
    created: 19.05.2022 18:59:45
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

bool matching_dfs(int v, vector<vector<int>>& g, vector<int>& from, vector<bool>& u) {
    u[v] = true;
    for (auto k : g[v]) {
        if (from[k] == -1 || (!u[from[k]] && matching_dfs(from[k], g, from, u))) {
            from[k] = v;
            return true;
        }
    }
    return false;
}

vector<pair<int, int>> find_matching(vector<vector<int>>& g, vector<int> a) {
    bool rev = false;
    if (2 * a.size() > g.size()) {
        rev = true;
        vector<bool> has(g.size(), false);
        for (auto v : a)
            has[v] = true;
        a.clear();
        a.reserve(g.size() - a.size());
        for (int i = 0; i < g.size(); ++i)
            if (!has[i])
                a.push_back(i);
    }
    vector<bool> u(g.size(), false);
    vector<int> from(g.size(), -1);
    for (auto v : a)
        if (matching_dfs(v, g, from, u))
            u.assign(g.size(), false);
    vector<pair<int, int>> result;
    for (int v = 0; v < from.size(); ++v) {
        if (from[v] != -1) {
            if (rev) result.emplace_back(v, from[v]);
            else result.emplace_back(from[v], v);
        }
    }
    return result;
}

void dominating_set_dfs(int v, vector<vector<int>>& g, vector<int>& with, vector<bool>& u,
                                                                          vector<bool>& take) {
    u[v] = true;
    for (auto k : g[v]) {
        take[k] = true;
        if (!u[with[k]])
            dominating_set_dfs(with[k], g, with, u, take);
    }
}

vector<int> find_dominating_set(vector<vector<int>>& g, vector<int>& a) {
    auto matching = find_matching(g, a);
    vector<int> with(g.size(), -1);
    for (auto edge : matching) {
        with[edge.first] = edge.second;
        with[edge.second] = edge.first;
    }
    vector<bool> u(g.size(), false);
    vector<bool> take(g.size(), false);
    for (auto v : a)
        if (with[v] == -1)
            dominating_set_dfs(v, g, with, u, take);
    for (auto e : matching)
        if (!take[e.second])
            take[e.first] = true;
    vector<int> result(matching.size());
    for (int i = 0; i < matching.size(); ++i) {
        if (take[matching[i].second]) result[i] = matching[i].second;
        else result[i] = matching[i].first;
    }
    return result;
}

vector<int> find_independent_set(vector<vector<int>>& g, vector<int>& a) {
    vector<int> result;
    vector<bool> u(g.size(), false);
    for (auto v : find_dominating_set(g, a))
        u[v] = true;
    for (int i = 0; i < g.size(); ++i)
        if (!u[i])
            result.push_back(i);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<ll> small, large;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (a * 3 <= m)
            small.pb(a);
        else
            large.pb(a);
    }

    vector<vector<int>> g(n);
    vector<int> a(large.size());
    iota(a.begin(), a.end(), 0);
    for (int i = 0; i < large.size(); ++i) {
        for (int j = 0; j < small.size(); ++j) {
            if (large[i] % small[j] == 0 && large[i] * 2 + small[j] <= m) {
                g[i].pb(j + large.size());
                g[j + large.size()].pb(i);
            }
        }
    }
    show(small, large);

    auto mt = find_matching(g, a);
    show(mt);
    if (mt.size() != large.size()) {
        cout << -1 << '\n';
        return 0;
    }
    vector<bool> U(small.size(), false);
    cout << small.size() << '\n';
    for (auto [u, v] : mt) {
        U[v - large.size()] = true;
        int a = large[u];
        int b = small[v - large.size()];
        cout << a * 2 + b << ' ' << a + b << '\n';
    }
    for (int i = 0; i < small.size(); ++i) {
        if (U[i]) continue;
        cout << small[i] * 3 << ' ' << small[i] * 2 << '\n';
    }

    return 0;
}