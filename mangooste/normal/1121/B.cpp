#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

namespace Debug {
    // #define DEBUG

    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()

const int M = 200001;
int n;
vector<int> a;
vector<char> can(M, 0);

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int &el : a)
        cin >> el;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            can[a[i] + a[j]] = 1;
    sort(all(a));
    debug(a);
    int ans = 0;
    for (int sm = 2; sm < M; sm++) {
        if (!can[sm])
            continue;
        int cnt = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && a[i] + a[j] > sm)
                j--;
            if (i < j && a[i] + a[j] == sm)
                cnt++, j--;
            i++;
        }
        debug(sm, cnt);
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}