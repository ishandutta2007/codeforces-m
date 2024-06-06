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
        int n;
        cin >> n;
        int power = 1;
        vector<int> ans;
        while (n != 0) {
            if (n % 10 != 0)
                ans.pb((n % 10) * power);
            power *= 10;
            n /= 10;
        }
        cout << ans.size() << '\n';
        for (auto el : ans)
            cout << el << ' ';
        cout << '\n';
    }
}