
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
        int x;
        cin >> x;
        int m = x % 10;
        cout << 10 * (m - 1) + (x == m ? 1 : x == m * 10 + m ? 3 : x == m * 100 + m * 10 + m ? 6 : 10) << '\n';
    }
}