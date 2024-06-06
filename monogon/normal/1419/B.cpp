
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
    int te;
    cin >> te;
    while(te--) {
        ll x;
        cin >> x;
        ll m = 0, cnt = 0;
        ll s = 1;
        while(cnt <= x) {
            m++;
            cnt += s * (s + 1) / 2;
            s = 2 * s + 1;
        }
        cout << m-1 << '\n';
    }
}