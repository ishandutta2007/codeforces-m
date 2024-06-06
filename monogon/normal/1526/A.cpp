
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
    n *= 2;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    rep(i, 0, n) {
        if(i % 2 == 0) {
            cout << a[i / 2] << ' ';
        }else {
            cout << a[n - i / 2 - 1] << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}