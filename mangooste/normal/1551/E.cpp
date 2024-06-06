#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    vector<int> new_dp(n + 1);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;

        fill(all(new_dp), -1);
        for (int shift = 0; shift <= n; shift++)
            if (dp[shift] != -1)
                new_dp[shift] = max(new_dp[shift], dp[shift] + (x == i - shift));

        for (int shift = 1; shift <= n; shift++)
            new_dp[shift] = max(new_dp[shift], dp[shift - 1]);

        swap(dp, new_dp);
    }

    for (int shift = 0; shift <= n; shift++)
        if (dp[shift] >= k) {
            cout << shift << '\n';
            return;
        }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}