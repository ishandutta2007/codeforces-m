/*
    author:  Maksim1744
    created: 17.04.2019 17:42:21
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

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
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

vector<vector<int>> g;
vector<int> c;
vector<bool> u;

void dfs(int v) {
    u[v] = true;
    bool leaf = true;
    c[v] = 0;
    for (auto k : g[v]) {
        dfs(k);
        leaf = false;
        c[v] += c[k];
    }
    if (leaf)
        c[v] = 1;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    c.resize(n);
    u.assign(n, false);
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].pb(i + 1);
    }
    dfs(0);
    sort(c.begin(), c.end());
    cout << c << '\n';
    return 0;
}