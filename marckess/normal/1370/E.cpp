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

int n;
string S, T, s, t;

void solve () {
	cin >> n >> S >> T;

	forn (i, n)
		if (S[i] != T[i]) {
			s.pb(S[i]);
			t.pb(T[i]);
		}

	sort(all(S));
	sort(all(T));

	if (S != T) {
		cout << -1 << endl;
		return;
	}

	int x = 0, y = 0, res = 0;

	for (char c : s) {
		if (c == '1') {
			if (x) x--, y++;
			else res++, y++;
		} else {
			if (y) x++, y--;
			else res++, x++;
		}
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}