
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n + 1), c(n + 1), suffmax(n + 2), seq0, seq1;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int cost = 0;
        if(a > b) {
            cost = 1;
            swap(a, b);
        }
        if(a <= n) {
            ve[a] = b;
            c[a] = cost;
        }else flag = false;
    }
    if(!flag) {
        cout << -1 << '\n';
        return;
    }
    suffmax[n + 1] = -1;
    for(int i = n; i >= 1; i--) {
        suffmax[i] = max(suffmax[i + 1], ve[i]);
    }
    int prefmin = INT_MAX;
    int cost0 = 0, cost1 = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        prefmin = min(prefmin, ve[i]);
        if(seq0.empty() || ve[seq0.back()] > ve[i]) {
            seq0.push_back(i);
            cost0 += c[i];
        }else if(seq1.empty() || ve[seq1.back()] > ve[i]) {
            seq1.push_back(i);
            cost1 += c[i];
        }else {
            cout << -1 << '\n';
            return;
        }
        if(prefmin > suffmax[i + 1]) {
            int s0 = (int) seq0.size(), s1 = (int) seq1.size();
            ans += min(cost0 + s1 - cost1, s0 - cost0 + cost1);
            cost0 = cost1 = 0;
            seq0.clear();
            seq1.clear();
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}