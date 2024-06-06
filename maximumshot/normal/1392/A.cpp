#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int ok = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != a[0])
                ok = 0;
        }
        cout << (ok ? n : 1) << "\n";
    }

    return 0;
}