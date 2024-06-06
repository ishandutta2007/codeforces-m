
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

bool ask(int x) {
    cout << x << endl;
    int b;
    cin >> b;
    return b;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int x = 0;
    rep(i, 0, n) {
        if(ask(i ^ x)) return;
        else x = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}