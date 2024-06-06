#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
 
ll a, k;

void solve () {
	cin >> a >> k;
	k--;

	while (k--) {
		string s = to_string(a);
		int mn = 9, mx = 0;

		for (char c : s) {
			mn = min(mn, c - '0');
			mx = max(mx, c - '0');
		}

		if (!mn) break;
		a += mx * mn;
	}

	cout << a << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	int t;
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}