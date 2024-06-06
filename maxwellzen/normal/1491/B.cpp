#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second
int t, n, u, v;
vi a;

void solve() {
    cin >> n >> u >> v;
    a.clear();
    a.rsz(n);
    F0R(i, n) cin >> a[i];
    F0R(i, n-1) {
        if (abs(a[i+1]-a[i])>1) {
            cout << 0 << '\n';
            return;
        }
    }
    F0R(i, n-1) {
        if (abs(a[i+1]-a[i])==1) {
            cout << min(u, v) << '\n';
            return;
        }
    }
    cout << min(u, v) + v << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}