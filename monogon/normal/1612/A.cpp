
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
    ll x, y;
    cin >> x >> y;
    if((x + y) % 2 != 0) {
        cout << -1 << ' ' << -1 << '\n';
        return;
    }
    if(x < y) {
        cout << 0 << ' ' << (x+y)/2 << '\n';
    }else {
        cout << (x+y)/2 << ' ' << 0 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}