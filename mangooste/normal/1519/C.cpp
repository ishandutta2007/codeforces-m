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
    int n;
    cin >> n;
    vector<vector<int>> vals(n);
    vector<int> where(n);
    for (auto &x : where)
        cin >> x, x--;

    for (int i = 0; i < n; i++) {
        int power;
        cin >> power;
        vals[where[i]].push_back(power);
    }

    vector<ll> answer(n);
    for (int i = 0; i < n; i++) {
        sort(rall(vals[i]));
        vector<ll> suf(len(vals[i]) + 1);
        for (int j = len(vals[i]) - 1; j >= 0; j--)
            suf[j] = suf[j + 1] + vals[i][j];

        for (int k = 1; k <= len(vals[i]); k++)
            answer[k - 1] += suf[0] - suf[len(vals[i]) / k * k];
    }

    for (auto x : answer)
        cout << x << ' ';

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}