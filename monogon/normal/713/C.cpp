
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

void solve() {
    int n;
    cin >> n;
    priority_queue<ll> Q;
    ll ans = 0;
    rep(i, 0, n) {
        ll a;
        cin >> a;
        a -= i;
        ans -= a;
        Q.push(a); Q.push(a);
        ans += Q.top(); Q.pop();
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}