
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
    vector<ll> a(n);
    ll p2 = 1;
    rep(i, 0, n) {
        cin >> a[i];
        while(a[i] % 2 == 0) {
            a[i] /= 2;
            p2 *= 2;
        }
    }
    sort(all(a));
    a.back() *= p2;
    cout << accumulate(all(a), 0LL) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}