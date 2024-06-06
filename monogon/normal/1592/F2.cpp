
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    vector<vector<bool>> flip(n + 1, vector<bool>(m + 1, false));
    vector<vector<int>> cnt(n + 1, vector<int>(m + 1, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            cnt[i][j] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1];
            if((s[i][j] == 'B') ^ (cnt[i][j] % 2)) {
                flip[i][j] = true;
                cnt[i][j]++;
            }
        }
    }
    int ans = cnt[0][0];
    vector<vi> g(n);
    vi mate(m, -1);
    rep(i, 0, n - 1) rep(j, 0, m - 1) {
        if(flip[i][j] && flip[i][m - 1] && flip[n - 1][j]) {
            g[i].push_back(j);
        }
    }
    int match = 0;
    vector<bool> vis(n, false);
    auto dfs = [&](auto dfs, int x) -> bool {
        vis[x] = true;
        for(int y : g[x]) {
            if(mate[y] == -1 || (!vis[mate[y]] && dfs(dfs, mate[y]))) {
                mate[y] = x;
                return true;
            }
        }
        return false;
    };
    rep(i, 0, n) {
        fill(all(vis), false);
        match += dfs(dfs, i);
    }
    if(match % 2 == 1) {
        if(flip[n - 1][m - 1]) ans--;
        else ans++;
    }
    ans -= match;
    cout << ans << '\n';
}