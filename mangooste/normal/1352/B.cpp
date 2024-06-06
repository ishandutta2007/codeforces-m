#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n - k + 1 > 0 && (n - k + 1) % 2 == 1) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++)
                cout << "1 ";
            cout << n - k + 1 << '\n';
            continue;
        }
        if (n - 2 * (k - 1) > 0 && (n - 2 * (k - 1)) % 2 == 0) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++)
                cout << "2 ";
            cout << n - 2 * (k - 1) << '\n';
            continue;
        }
        cout << "NO\n";
    }
}