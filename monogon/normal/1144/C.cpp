
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define ll long long
#define VI vector<int>

using namespace std;

const int MAX_N = 2e5 + 5;
int n;
int a[MAX_N];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    FOR(i, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<int> s[2];
    FOR(i, n) {
        if(i >= 2 && a[i] == a[i - 2]) {
            cout << "NO" << endl;
            return 0;
        }
        s[i % 2].push_back(a[i]);
    }
    cout << "YES" << endl << s[0].size() << endl;
    for(int x : s[0]) {
        cout << x << " ";
    }
    cout << endl << s[1].size() << endl;
    reverse(all(s[1]));
    for(int x : s[1]) {
        cout << x << " ";
    }
    cout << endl;
}