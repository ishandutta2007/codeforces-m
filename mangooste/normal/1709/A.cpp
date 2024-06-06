#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

void solve(int test_num) {
    int pos;
    cin >> pos, pos--;
    array<int, 3> to;
    for (auto &x : to) cin >> x, x--;

    array<bool, 3> used{};
    while (!used[pos]) {
        used[pos] = true;
        pos = to[pos];
        if (pos == -1) break;
    }

    cout << (used[0] && used[1] && used[2] ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}