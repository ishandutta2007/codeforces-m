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

const int MX = 105;
int n, m, x, l[MX], r[MX], mn, mx;

void solve () {
	cin >> n >> x >> m;
	mx = mn = x;

	forn (i, m) {
		cin >> l[i] >> r[i];
		if (r[i] < mn || mx < l[i]) continue;

		mn = min(mn, l[i]);
		mx = max(mx, r[i]);
	}

	cout << mx - mn + 1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}