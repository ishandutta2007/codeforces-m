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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX];
ll sum, res, ap, ai, mp, mi;

void solve () {
	sum = 0;

	cin >> n;
	forn (i, n) {
		cin >> a[i];
		if (i % 2 == 0) sum += a[i];
	}

	ap = 0, ai = 0;
	mp = 1e18, mi = 0;
	res = sum;

	forn (i, n) {
		if (i % 2) {
			ai += a[i], ap += a[i];
			mi = min(mi, ai);
			res = max(res, sum + ai - mi);
		} else {
			ai -= a[i], ap -= a[i];
			mp = min(mp, ap);
			res = max(res, sum + ap - mp);
		}
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}